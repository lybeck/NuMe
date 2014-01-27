/* 
 * File:   w2e5.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <functional>
#include "nr.h"
#include "eps.h"

using namespace std;

#define PRINT_ITERATION

int main() {

    bool print_iteration = true;

    double (*g) (double) = [] (double x) {
        return pow(sin(x), 2);
    };
    auto f = [g] (double x) {
        return NR::qtrap(g, 0, x);
    };

    double eps = get_sqrt_machine_epsilon();
    int max_iter = 100;

    double y = 5.0;
    double a = 0;
    double b = 100;
    double a0, b0, x;
    auto h = [f] (double x) {
        return f(x) - 5;
    };

    cout.precision(15);

    for (int i = 0; i < max_iter; i++) {
        a0 = a;
        b0 = b;
        x = (a + b) / 2;
        if (h(a) * h(x) < 0)
            b = x;
        if (h(b) * h(x) < 0)
            a = x;

#ifdef PRINT_ITERATION
        cout << "Iteration " << i + 1 << ":" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "x = " << x << endl;
        cout << "f(x) = " << f(x) << endl << endl;
#endif

        if (abs(a - b) < eps || abs(h(x)) < eps)
            break;
    }

    cout << endl << "Iteration result:" << endl;
    cout << "x = " << x << endl;
    cout << "f(x) = " << f(x) << endl;
    cout << endl;


    return 0;
}

