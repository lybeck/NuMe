/* 
 * File:   w3e5.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <complex>
#include "nr.h"
#include "matutl02.h"
#include "eps.h"

using namespace std;

const double MIN_VAL = -1000;
const double MAX_VAL = 1000;

void eigen(Mat_DP a, Vec_CPLX_DP &w) {
    NR::balanc(a);
    NR::elmhes(a);
    NR::hqr(a, w);
}

void random_matrix(Mat_DP& a) {
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            a[i][j] = rdm(MIN_VAL, MAX_VAL);
        }
    }
}

double diagonal_sum(Mat_DP const& a) {
    double sum = 0;
    for (int i = 0; i < min(a.nrows(), a.ncols()); i++) {
        sum += a[i][i];
    }
    return sum;
}

bool is_eig_sum_success(Mat_DP const& a, double tolerance) {
    if (a.nrows() != a.ncols()) {
        cerr << "Matrix not a square matrix! Cannot run eigenvalue sum test." << endl;
        return false;
    }
    int n = a.nrows();
    double diag_sum = diagonal_sum(a);
    Vec_CPLX_DP eig(n);
    eigen(a, eig);
    complex<double> eig_sum(0.0, 0.0);
    for (int i = 0; i < n; i++) {
        complex<double> d(eig[i]);
        eig_sum += d;
    }
    return abs(eig_sum - diag_sum) < tolerance;
}

bool is_det_success(Mat_DP const& a, double tolerance) {
    return true;
}

void run_tests(int minn, int maxn, int tests, double tolerance) {

    cout << "Starting tests" << endl;

    int totalTests = (maxn - minn + 1) * tests;
    int eig_fails = 0;
    int det_fails = 0;
    for (int n = minn; n <= maxn; n++) {
        cout << "n = " << n << endl;
        Mat_DP a(n, n);
        for (int i = 0; i < tests; i++) {
            random_matrix(a);
            if (!is_eig_sum_success(a, tolerance))
                ++eig_fails;
            if (!is_det_success(a, tolerance))
                ++det_fails;
        }
    }
    cout << "Total tests: " << totalTests << endl;
    cout << "Fails on eigenvalue sum test: " << eig_fails << endl;
    cout << "Fails on determinant test: " << det_fails << endl;
}

int main() {

    //    init_srand();

    Mat_DP a(4, 4);
    random_matrix(a);
    Vec_CPLX_DP e(4);
    eigen(a, e);

    double eps = get_sqrt_machine_epsilon();
    run_tests(3, 30, 100, eps);

    //    Mat_DP a(3,3);
    //    a[0][0] = 0;
    //    a[0][1] = 1;
    //    a[1][0] = -1;
    //    a[1][1] = 0;
    //    cout << a << endl;
    //    Vec_CPLX_DP e(a.nrows());
    //    eigen(a, e);
    //    for (int i = 0; i < e.size(); i++) {
    //        cout << e[i] << endl;
    //    }

    return 0;
}

