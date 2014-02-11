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

bool eq(Mat_DP const& a, Mat_DP const& b, double tolerance) {
    if (a.nrows() != b.nrows() || a.ncols() != b.ncols())
        return false;
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = 0; j < a.ncols(); j++) {
            if (abs(a[i][j] / b[i][j] - 1) > tolerance)
                return false;
        }
    }
    return true;
}

bool test_a(int n, int m, double tolerance) {
    Mat_DP a(n, m), pinva(m, n), b(n, m);
    ranmat2(a, min_val, max_val);
    pseudoinv(a, pinva);
    pseudoinv(pinva, b);

//    cout << endl << "a = " << endl << a << endl;
//    cout << endl << "pinva = " << endl << pinva << endl;
//    cout << endl << "b = " << endl << b << endl;

    return eq(a, b, tolerance);
}

void run_test(test t, int minn, int maxn, int times, double tolerance) {
    int total = pow(maxn - minn + 1, 2) * times;
    int fails = 0;
    for (int n = minn; n <= maxn; n++) {
        for (int m = minn; m <= maxn; m++) {
            for (int i = 0; i < times; i++) {
                if (!t(n, m, tolerance)) {
                    ++fails;
                    cout << "FAIL! (n, m) = " << n << ", " << m << endl;
                }
            }
        }
    }
    cout << "total = " << total << endl;
    cout << "fails = " << fails << endl;
}

int main() {
    
    double eps = get_sqrt_machine_epsilon();
    run_test(test_a, 1, 30, 10, eps);

    return 0;
}

