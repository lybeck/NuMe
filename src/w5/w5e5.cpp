/* 
 * File:   w5e5.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <solve.h>
#include "nr.h"
#include "matutl02.h"
#include "eps.h"

using namespace std;

typedef bool (*test) (int, int, double);

const double min_val = -1e2;
const double max_val = 1e2;

bool eq(Mat_DP const& a, Mat_DP const& b, double tolerance = 1e-6) {
    if (a.nrows() != b.nrows() || a.ncols() != b.ncols())
        return false;
    Mat_DP c(a.nrows(), a.ncols());
    double sum = 0;
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            sum += pow((a[i][j] - b[i][j]), 2);
        }
    }
    return pow(sum, .5) < tolerance;
}

bool test_a(int n, int m, double tolerance) {
    Mat_DP a(n, m), pinva(m, n), b(n, m);
    ranmat2(a, min_val, max_val);
    pseudoinv(a, pinva);
    pseudoinv(pinva, b);
    return eq(a, b, tolerance);
}

bool test_b(int n, int m, double tolerance) {
    Mat_DP a(n, m), at(m, n), pinva(m, n), b(n, m), c(n, m);
    ranmat2(a, min_val, max_val);

    transp(a, at);
    pseudoinv(at, b);

    pseudoinv(a, pinva);
    transp(pinva, c);

    return eq(b, c, tolerance);
}

bool test_c(int n, int m, double tolerance) {
    int p = (n + m) * rdm(0, 1) + 1;
    Mat_DP a(n, m), b(m, p), ab(n, p), pinva(m, n), pinvb(p, m), m1(p, n), m2(p, n);
    ranmat2(a, min_val, max_val);
    ranmat2(b, min_val, max_val);

    matmul(a, b, ab);
    pseudoinv(ab, m1);

    pseudoinv(a, pinva);
    pseudoinv(b, pinvb);
    matmul(pinvb, pinva, m2);
    
    return eq(m1, m2, tolerance);
}

void run_test(test t, int minn, int maxn, int times, double tolerance) {
    int total = 0;
    int fails = 0;
    for (int n = minn; n <= maxn; n++) {
        for (int m = minn; m <= n; m++) {
            for (int i = 0; i < times; i++) {
                ++total;
                if (!t(n, m, tolerance))
                    ++fails;
            }
        }
    }
    cout << "Total tests  = " << total << endl;
    cout << "Failed tests = " << fails << endl;
    cout << "Fail ratio   = " << 100.0 * fails / total << " %" << endl;
}

int main() {

    init_srand();

    double eps = get_sqrt_machine_epsilon();
    int minn = 1;
    int maxn = 25;
    int times = 10;

    cout << endl << "Testing for pinv(pinv(A)) == A..." << endl;
    run_test(test_a, minn, maxn, times, eps);
    cout << endl << "Testing for transp(pinv(A)) == pinv(transp(A))..." << endl;
    run_test(test_b, minn, maxn, times, eps);
    cout << endl << "Testing for pinv(A * B) == pinv(B) * pinv(A)..." << endl;
    run_test(test_c, minn, maxn, times, eps);
    cout << endl;

    return 0;
}

