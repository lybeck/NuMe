/*
 * File:   w11e4.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <solve.h>
#include "nr.h"
#include "matutl02.h"
#include "der.h"

using namespace std;

double theta;
const int total_tests = 100;

void test_a() {

    cout << "Test a" << endl;

    int max_iter = 1e6;
    double tol = 1e-6;
    double dt = M_PI / (total_tests);
    int tests_passed = 0;
    for (int i = 1; i <= total_tests; i++) {
        theta = i * dt;
        double expected = (M_PI - theta) / 2;

        double s = 0.0;
        bool converged = false;
        for (int k = 1; k <= max_iter; k++) {
            s += sin(k * theta) / k;
            if (abs(s - expected) < tol) {
                converged = true;
                break;
            }
        }
        if (converged)
            ++tests_passed;
    }

    cout << tests_passed << " of " << total_tests << " tests passed." << endl << endl;
}

void test_b() {

    cout << "Test b" << endl;

    int max_iter = 1e5;
    double dt = M_PI / (total_tests + 1);
    int tests_passed = 0;
    for (int i = 1; i <= total_tests; i++) {
        theta = i * dt;

        double s = 0.0;
        bool negative = false;
        for (int k = 1; k <= max_iter; k++) {
            s += sin(k * theta) / k;
            if (s < 0) {
                negative = true;
                break;
            }
        }
        if (!negative)
            ++tests_passed;
    }

    cout << tests_passed << " of " << total_tests << " tests passed." << endl << endl;
}

double k0;

double f(double theta) {
    return sin(k0 * theta) / (k0 * sin(theta / 2));
}

void test_c() {

    cout << "Test c" << endl;

    int max_iter = 1e4;
    double dt = M_PI / (total_tests + 1);
    int tests_passed = 0;
    for (int i = 1; i <= total_tests; i++) {
        theta = i * dt;

        double s = 0.0;
        bool positive = false;
        for (int k = 1; k <= max_iter; k++) {
            k0 = k;
            s += myder::der(f, theta);
            if (s > 0) {
                positive = true;
                break;
            }
        }
        if (!positive)
            ++tests_passed;
    }

    cout << tests_passed << " of " << total_tests << " tests passed." << endl << endl;
}

int main() {
    test_a();
    test_b();
    test_c();
    return 0;
}
