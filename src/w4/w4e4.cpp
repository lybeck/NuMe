/* 
 * File:   w4e4.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "nr.h"
#include "matutl02.h"

#define inf INFINITY

using namespace std;

double operator *(Vec_DP const& v, Vec_DP const& w) {
    if (v.size() != w.size())
        throw runtime_error("Vector dimensions mismatch in dot product!");
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i] * w[i];
    }
    return sum;
}

double norm_inf(Vec_DP const& v) {
    double max = 0;
    double tmp;
    for (int i = 0; i < v.size(); i++) {
        tmp = abs(v[i]);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

double norm_p(Vec_DP const& v, double p) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += pow(abs(v[i]), p);
    }
    return pow(sum, 1 / p);
}

double norm(Vec_DP const& v, double p) {
    if (p <= 0)
        return NAN;
    if (p == inf)
        return norm_inf(v);
    return norm_p(v, p);
}

Vec_DP& get_col(Mat_DP const& a, int j, Vec_DP& v) {
    if (j >= a.ncols()) {
        throw runtime_error("Column index exceeds number of columns!");
    }
    for (int i = 0; i < a.nrows(); i++) {
        v[i] = a[i][j];
    }
    return v;
}

void set_col(Mat_DP& a, int j, Vec_DP const& v) {
    if (j >= a.ncols())
        throw runtime_error("Column index exceeds number of columns in function set_col!");
    for (int i = 0; i < a.nrows(); i++) {
        a[i][j] = v[i];
    }
}

vector<double> col_norms(Mat_DP const& a, double p) {
    int cols = a.ncols();
    Vec_DP c(a.nrows());
    vector<double> d(cols);
    for (int i = 0; i < cols; i++) {
        d[i] = norm(get_col(a, i, c), p);
    }
    return d;
}

void normalize_columns(Mat_DP const& a, Mat_DP& b, double p) {
    if (a.nrows() != b.nrows() || a.ncols() != b.ncols())
        throw runtime_error("Matrix dimensions mismatch in function normalize_columns!");
    Vec_DP c(a.nrows());
    vector<double> norms = col_norms(a, p);
    for (int i = 0; i < a.ncols(); i++) {
        get_col(a, i, c);
        for (int j = 0; j < c.size(); j++) {
            c[j] /= norms[i];
        }
        set_col(b, i, c);
    }
}

void scal_prod_mat(Mat_DP const& a, Mat_DP& b, double p) {
    int n = a.nrows();
    int m = a.ncols();
    if (b.nrows() != m || b.ncols() != m)
        throw runtime_error("Matrix b should have as many rows and columns as matrix a has columns in funcion scal_prod_mat!");
    Mat_DP c(n, m);
    normalize_columns(a, c, p);
    vector<Vec_DP> cols(m);
    for (int i = 0; i < m; i++) {
        Vec_DP col(n);
        cols[i] = get_col(c, i, col);
    }
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            if (i == j)
                b[i][i] = cols[i] * cols[i];
            else
                b[i][j] = b[j][i] = cols[i] * cols[j];
        }
    }
}

void run_norm_test(Mat_DP const& a, double p) {

    cout << endl << "a = " << endl << a << endl;

    vector<double> n = col_norms(a, p);
    cout << fixed;
    int prec = cout.precision();
    cout.precision(2);
    cout << p << "-norms for columns:" << endl;
    cout.precision(prec);
    for (int i = 0; i < n.size(); i++) {
        cout << setw(14) << n[i];
    }
    cout << endl << endl;
}

void run_normalize_test(Mat_DP const& a, double p) {
    Mat_DP b(a.nrows(), a.ncols());
    normalize_columns(a, b, p);

    cout << "b = " << endl << b << endl;

    vector<double> n = col_norms(b, p);
    cout << fixed;
    int prec = cout.precision();
    cout.precision(2);
    cout << p << "-norms for columns:" << endl;
    cout.precision(prec);
    for (int i = 0; i < n.size(); i++) {
        cout << setw(14) << n[i];
    }
    cout << endl << endl;
}

void run_dot_mat_test(Mat_DP const& a, double p) {
    Mat_DP b(a.ncols(), a.ncols());
    scal_prod_mat(a, b, p);

    cout << "Scalar product matrix:" << endl << b << endl;
}

int main() {

    init_srand();

    int n = 5;
    int m = 3;

    double p = 2;

    Mat_DP a(n, m);
    ranmat2(a, -10, 10);

    run_norm_test(a, p);
    run_normalize_test(a, p);
    run_dot_mat_test(a, p);

    return 0;
}

