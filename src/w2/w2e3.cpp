/* 
 * File:   w2e3.cpp
 * Author: Lasse Lybeck
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "nr.h"
#include "matutl02.h"
#include "eps.h"

using namespace std;

const double minValue = -1e3;
const double maxValue = 1e3;

bool is_zero_matrix(Mat_DP const& a, double tolerance) {
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            if(abs(a[i][j]) > tolerance)
                return false;
        }
    }
    return true;
}

Mat_DP create_test_matrix(Mat_DP const& P, Mat_DP const& R) {
    int p = P.nrows();
    int r = R.nrows();
    int n = p + r;
    Mat_DP A(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < p) {
                if (j < p)
                    A[i][j] = P[i][j];
                else
                    A[i][j] = 0;
            } else {
                if (j >= p)
                    A[i][j] = R[i - p][j - p];
                else
                    A[i][j] = 0;
            }
        }
    }
    return A;
}

Mat_DP get_random_matrix(int n) {
    Mat_DP mat(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = rdm(minValue, maxValue);
        }
    }
    return mat;
}

bool test_mat_inverse(int p, int r, double tolerance) {
    Mat_DP P = get_random_matrix(p);
    Mat_DP R = get_random_matrix(r);
    Mat_DP Pinv(p, p), Rinv(r, r);
    invmat(P, Pinv);
    invmat(R, Rinv);

    int n = p + r;
    Mat_DP A = create_test_matrix(P, R);
    Mat_DP B = create_test_matrix(Pinv, Rinv);
    Mat_DP Ainv(n, n);
    invmat(A, Ainv);
    
    return is_zero_matrix(Ainv - B, tolerance);
}

void run_test(int minn, int maxn, int times, double tolerance) {
    int totaln = (maxn - minn + 1);
    int tests = times * totaln * totaln;
    int fails = 0;
    for (int p = minn; p <= maxn; p++) {
        for (int r = minn; r <= maxn; r++) {
            for (int i = 0; i < times; i++) {
                if (!test_mat_inverse(p, r, tolerance))
                    ++fails;
            }
        }
    }
    cout << "tests = " << tests << endl;
    cout << "fails = " << fails << endl;
}

int main() {

    init_srand();

    double eps = get_sqrt_machine_epsilon();

    run_test(1, 20, 10, eps);

    return 0;
}
