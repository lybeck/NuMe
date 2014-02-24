/* 
 * File:   w2e4.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "nr.h"
#include "matutl02.h"
#include "eps.h"

using namespace std;

const double minValue = -1e3;
const double maxValue = 1e3;

typedef bool (*test_case) (int, double);

bool is_upper_triangular(Mat_DP const& a, double tolerance) {
    int n = a.nrows();
    int m = a.ncols();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < min(i, m); j++) {
            if (abs(a[i][j]) > tolerance) {
                cout << "For a " << n << " x " << m << " matrix: value at (" << i << ", " << j << ") = " << a[i][j] << endl;
                return false;
            }
        }
    }
    return true;
}

void zero_under_diag(Mat_DP& a) {
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < min(i, a.ncols()); j++) {
            a[i][j] = 0;
        }
    }
}

void random_upper_triangular(Mat_DP& a) {

    // could be done like this, but we do it more efficiently
    //    ranmat2(a, minValue, maxValue);
    //    zero_under_diag(a);

    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            if (i <= j)
                a[i][j] = rdm(minValue, maxValue);
            else
                a[i][j] = 0;
        }
    }
}

bool is_inverse_upper_triangular(int n, double tolerance) {
    Mat_DP a(n, n);
    random_upper_triangular(a);
    Mat_DP ainv(n, n);
    invmat(a, ainv);
    return is_upper_triangular(ainv, tolerance);
}

bool is_product_upper_triangular(int n, double tolerance) {
    Mat_DP a(n, n), b(n, n);
    random_upper_triangular(a);
    random_upper_triangular(b);
    Mat_DP c = a * b;
    return is_upper_triangular(c, tolerance);
}

void random_tridiagonal(Mat_DP& a) {
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            if (abs(i - j) <= 1)
                a[i][j] = rdm(minValue, maxValue);
            else
                a[i][j] = 0;
        }
    }
}

bool is_tridiagonal(Mat_DP& a, double tolerance) {
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            if (abs(i - j) > 1 && abs(a[i][j]) > tolerance)
                return false;
        }
    }
    return true;
}

bool is_inverse_tridiagonal(int n, double tolerance) {
    Mat_DP a(n, n);
    random_tridiagonal(a);
    Mat_DP ainv(n, n);
    invmat(a, ainv);
    return is_tridiagonal(ainv, tolerance);
}

bool is_product_tridiagonal(int n, double tolerance) {
    Mat_DP a(n, n), b(n, n);
    random_tridiagonal(a);
    random_tridiagonal(b);
    Mat_DP c = a * b;
    return is_tridiagonal(c, tolerance);
}

void run_tests(test_case test, int minn, int maxn, int tests, double tolerance) {
    int totalTests = (maxn - minn + 1) * tests;
    int fails = 0;
    for (int n = minn; n <= maxn; n++) {
        for (int i = 0; i < tests; i++) {
            if (!test(n, tolerance))
                ++fails;
        }
    }

    cout << "totalTests = " << totalTests << endl;
    cout << "fails = " << fails << endl;
    cout << "ratio = " << (double) 100 * fails / totalTests << " %" << endl;
}

int main() {

    init_srand();

    const double eps = get_sqrt_machine_epsilon();

    int minn = 4;
    int maxn = 30;
    int tests = 100;

    cout << endl << "Starting tests for upper triangular inverse." << endl;
    run_tests(&is_inverse_upper_triangular, minn, maxn, tests, eps);

    cout << endl << "Starting tests for upper triangular product." << endl;
    run_tests(&is_product_upper_triangular, minn, maxn, tests, eps);

    cout << endl << "Starting tests for tridiagonal inverse." << endl;
    run_tests(&is_inverse_tridiagonal, minn, maxn, tests, eps);

    cout << endl << "Starting tests for tridiagonal product." << endl;
    run_tests(&is_product_tridiagonal, minn, maxn, tests, eps);

    cout << endl;

    return 0;
}

