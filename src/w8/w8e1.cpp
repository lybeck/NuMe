/* 
 * File:   w8e1.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <solve.h>
#include "matutl02.h"
#include "nr.h"

using namespace std;

Vec_CPLX_DP operator-(Vec_CPLX_DP const& v, Vec_CPLX_DP const& w) {
    Vec_CPLX_DP res(v.size());
    for (int i = 0; i < v.size(); i++) {
        res[i] = v[i] - w[i];
    }
    return res;
}

Vec_CPLX_DP operator*(Mat_CPLX_DP const& A, Vec_CPLX_DP const& b) {
    Vec_CPLX_DP res(A.nrows());
    for (int i = 0; i < A.nrows(); i++) {
        res[i] = 0;
        for (int j = 0; j < A.ncols(); j++) {
            res[i] += A[i][j] * b[j];
        }
    }
    return res;
}

double cplx_norm(Vec_CPLX_DP const& v) {
    double res = 0;
    for (int i = 0; i < v.size(); i++) {
        res += (v[i].real() * v[i].real() + v[i].imag() * v[i].imag());
    }
    return sqrt(res);
}

double error_norm(Mat_CPLX_DP const& G, Vec_CPLX_DP const& w, Vec_CPLX_DP const& z) {
    Vec_CPLX_DP tmp = G * z;
    Vec_CPLX_DP diff = tmp - w;
    return cplx_norm(diff);
}

void create_cplx_vec(Vec_DP const& a, Vec_CPLX_DP& v) {
    if (a.size() != 2 * v.size())
        throw runtime_error("Dimensions mismatch in create_cplx_vec!");
    int n = v.size();
    for (int i = 0; i < n; i++) {
        v[i].real(a[i]);
        v[i].imag(a[n + i]);
    }
}

void create_vec(Vec_DP const& b, Vec_DP const& d, Vec_DP& f) {
    for (int i = 0; i < b.size(); i++) {
        f[i] = b[i];
        f[b.size() + i] = d[i];
    }
}

void create_coef_mat(Mat_DP const& A, Mat_DP const& C, Mat_DP& E) {
    for (int i = 0; i < A.nrows(); i++) {
        for (int j = 0; j < A.ncols(); j++) {
            E[i][j] = A[i][j];
            E[A.nrows() + i][j] = C[i][j];
            E[i][A.ncols() + j] = -C[i][j];
            E[A.nrows() + i][A.ncols() + j] = A[i][j];
        }
    }
}

void split_vec(Vec_CPLX_DP const& w, Vec_DP& b, Vec_DP& d) {
    for (int i = 0; i < w.size(); i++) {
        b[i] = w[i].real();
        d[i] = w[i].imag();
    }
}

void split_mat(Mat_CPLX_DP const& G, Mat_DP& A, Mat_DP& C) {
    for (int i = 0; i < G.nrows(); i++) {
        for (int j = 0; j < G.ncols(); j++) {
            A[i][j] = G[i][j].real();
            C[i][j] = G[i][j].imag();
        }
    }
}

void ran_cplx_vec(Vec_CPLX_DP& v, double min, double max) {
    for (int i = 0; i < v.size(); i++) {
        complex<double> z(rdm(min, max), rdm(min, max));
        v[i] = z;
    }
}

void ran_cplx_mat(Mat_CPLX_DP& G, double min, double max) {
    for (int i = 0; i < G.nrows(); i++) {
        for (int j = 0; j < G.ncols(); j++) {
            complex<double> z(rdm(min, max), rdm(min, max));
            G[i][j] = z;
        }
    }
}

void solve(Mat_CPLX_DP const& G, Vec_CPLX_DP const& w, Vec_CPLX_DP& z) {
    if (G.nrows() != G.ncols() || G.nrows() != w.size() || G.nrows() != z.size()) {
        throw runtime_error("Dimensions mismatch!");
    }
    int n = G.nrows();
    Mat_DP A(n, n), C(n, n), E(2 * n, 2 * n);
    Vec_DP b(n), d(n), f(2 * n), x(2 * n);
    split_mat(G, A, C);
    split_vec(w, b, d);
    create_coef_mat(A, C, E);
    create_vec(b, d, f);

    LUsolve(E, f, x);

    create_cplx_vec(x, z);
}

void run_test() {
    int n = 20;
    Mat_CPLX_DP G(n, n);
    Vec_CPLX_DP w(n), z(n);
    ran_cplx_mat(G, -10.0, 10.0);
    ran_cplx_vec(w, -10.0, 10.0);

    solve(G, w, z);

    double error = error_norm(G, w, z);
    
    cout << scientific;
    cout << "error = " << error << endl;
    cout << fixed;
}

int main() {

    init_srand();

    run_test();

    return 0;
}

