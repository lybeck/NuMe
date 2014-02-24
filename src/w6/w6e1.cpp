/* 
 * File:   w6e1.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include "matutl02.h"
#include "nr.h"
#include "eps.h"
#include "myeigen.h"

using namespace std;

bool is_sym(Mat_DP const& a) {
    if (a.nrows() != a.ncols())
        return false;
    double tol = get_sqrt_machine_epsilon();
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = i + 1; j < a.ncols(); j++) {
            if (abs(a[i][j] - a[j][i]) > tol) {
                return false;
            }
        }
    }
    return true;
}

bool is_pos_def(Mat_DP const& a, bool print) {
    if (!is_sym(a))
        return false;
    Vec_CPLX_DP e(a.nrows());
    myeigen(a, e);

    if (print) {
        cout << "Eigenvalues:" << endl;
        for (int i = 0; i < e.size(); i++) {
            cout << e[i] << endl;
        }
    }

    for (int i = 0; i < e.size(); i++) {
        if (e[i].real() <= 0)
            return false;
    }
    return true;
}

bool is_pos_def(Mat_DP const& a) {
    return is_pos_def(a, false);
}

void make_pos_def(Mat_DP a, Mat_DP& b) {
    if (!is_sym(a))
        throw runtime_error("Function make_pos_def can only be used on symmetric matrices!");
    int n = a.nrows();
    Vec_CPLX_DP e(n);
    myeigen(a, e);
    double c = 0;
    double eig;
    for (int i = 0; i < n; i++) {
        eig = e[i].real();
        if (eig < c)
            c = eig;
    }
    c = 1 - c;

    Mat_DP I(n, n), cI(n, n);
    unitmat(I);
    scalmatmul(I, c, cI);
    matsum(a, cI, b);
}

void ran_sym(Mat_DP& a) {
    if (a.nrows() != a.ncols())
        throw runtime_error("Matrix must be n x n to create random symmetric matrix!");
    int n = a.nrows();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j)
                a[i][i] = rdm(-10, 10);
            else
                a[i][j] = a[j][i] = rdm(-10, 10);
        }
    }
}

void ran_pos_def(Mat_DP& a) {
    ran_sym(a);
    make_pos_def(a, a);
}

void test_make_pos_def() {
    cout << endl;

    int n = rdm(3, 15);
    cout << "n = " << n << endl << endl;

    Mat_DP a(n, n), b(n, n);
    ran_sym(a);

    cout << "Before make_pos_def." << endl;
    bool pos_def = is_pos_def(a, true);
    cout << "Positive definite: " << pos_def << endl << endl;

    make_pos_def(a, b);

    cout << endl << "After make_pos_def." << endl;
    pos_def = is_pos_def(b, true);
    cout << "Positive definite: " << pos_def << endl << endl;
}

bool ran_bool() {
    return rdm(0, 1) < .5;
}

void hadamard_prod(Mat_DP const& a, Mat_DP const& b, Mat_DP& c) {
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
}

void test_hadamard() {
    int tests = 100;
    int maxn = 20;
    int c = 0;
    int fails = 0;
    for (int n = 1; n <= maxn; n++) {
        Mat_DP a(n, n), b(n, n), h(n, n);
        for (int i = 0; i < tests; i++) {
            ran_pos_def(a);
            ran_pos_def(b);
            hadamard_prod(a, b, h);
            ++c;
            if (!is_pos_def(h))
                ++fails;
        }
    }

    cout << "Hadamard test:" << endl;
    cout << "Total tests = " << c << endl;
    cout << "Fails = " << fails << endl << endl;
}

int main() {

    init_srand();

    test_make_pos_def();
    //    getchar();
    test_hadamard();

    return 0;
}
