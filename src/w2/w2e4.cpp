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

bool is_inverse_upper_triangular(int n, double tolerance) {
    Mat_DP a(n, n);
    ranmat2(a, minValue, maxValue);
    zero_under_diag(a);
    Mat_DP ainv(n, n);
    invmat(a, ainv);
    //    cout << "a = " << endl << a << endl;
    //    cout << "ainv = " << endl << ainv << endl;
    return is_upper_triangular(ainv, tolerance);
}

void test_upper_triangular(int minn, int maxn, int tests, double tolerance) {
    int totalTests = (maxn - minn + 1) * tests;
    int fails = 0;
    for (int n = minn; n <= maxn; n++) {
        for (int i = 0; i < tests; i++) {
            if (!is_inverse_upper_triangular(n, tolerance))
                ++fails;
        }
    }

    cout << "totalTests = " << totalTests << endl;
    cout << "fails = " << fails << endl;
    cout << "ratio = " << (double) 100 * fails / totalTests << " %" << endl;
}

int main() {

    init_srand();

    double eps = get_sqrt_machine_epsilon();

    int minn = 1;
    int maxn = 30;
    int tests = 100;

    cout << endl;
    cout << "Starting test for upper triangular matrices." << endl;
    test_upper_triangular(minn, maxn, tests, eps);

    return 0;
}

