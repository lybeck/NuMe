/* 
 * File:   w3e1.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include "nr.h"
#include "matutl02.h"
#include "eps.h"

using namespace std;

const double MIN_VAL = -1e3;
const double MAX_VAL = 1e3;

void usolve(Mat_DP const& A, Vec_DP const& b, Vec_DP& x) {
    for (int i = b.size() - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = b.size() - 1; j > i; --j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

void lsolve(Mat_DP const& A, Vec_DP const& b, Vec_DP& x) {
    for (int i = 0; i < b.size(); ++i) {
        x[i] = b[i];
        for (int j = 0; j < i; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

void random_vector(Vec_DP& v) {
    ranvec(v, MIN_VAL, MAX_VAL);
}

void random_upper_triangular(Mat_DP& a) {
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            a[i][j] = i <= j ? rdm(MIN_VAL, MAX_VAL) : 0;
        }
    }
}

void random_lower_triangular(Mat_DP& a) {
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            a[i][j] = i >= j ? rdm(MIN_VAL, MAX_VAL) : 0;
        }
    }
}

bool vector_equals(Vec_DP const& a, Vec_DP const& b, double tolerance) {
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++) {
        if (abs(1 - a[i] / b[i]) > tolerance) {
            //            cout << "n = " << b.size() << " diff = " << abs(a[i] - b[i]) << endl;
            return false;
        }
    }
    return true;
}

bool test_usolve(int n, double tolerance) {
    Mat_DP A(n, n);
    random_upper_triangular(A);
    Vec_DP b(n);
    random_vector(b);
    Vec_DP x(n);
    usolve(A, b, x);
    return vector_equals(A * x, b, tolerance);
}

bool test_lsolve(int n, double tolerance) {
    Mat_DP A(n, n);
    random_lower_triangular(A);
    Vec_DP b(n);
    random_vector(b);
    Vec_DP x(n);
    lsolve(A, b, x);
    return vector_equals(A * x, b, tolerance);
}

void run_tests(int minn, int maxn, int tests, double tolerance) {
    int totalTests = (maxn - minn + 1) * tests;
    int fails_upper = 0;
    int fails_lower = 0;
    for (int i = minn; i <= maxn; i++) {
        for (int j = 0; j < tests; j++) {
            if (!test_usolve(i, tolerance))
                ++fails_upper;
            if (!test_lsolve(i, tolerance))
                ++fails_lower;
        }
    }

    cout << "Tests run: " << totalTests << endl;
    cout << "Fails by upper triangular solver: " << fails_upper << ", ratio = " << 100.0 * fails_upper / totalTests << "%" << endl;
    cout << "Fails by lower triangular solver: " << fails_lower << ", ratio = " << 100.0 * fails_lower / totalTests << "%" << endl;
}

int main() {

    init_srand();

    //    double eps = get_sqrt_machine_epsilon();
    double eps = 1e-4;

    run_tests(1, 30, 10, eps);

    return 0;
}

