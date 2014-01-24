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

int main() {
    
    bool print_iteration = true;
    
    double (*g) (double) = [] (double x) {return pow(sin(x), 2);};
    auto f = [g] (double x) {return NR::qtrap(g, 0, x);};
    
    double eps = get_sqrt_machine_epsilon();
    int max_iter = 100;
    
    double y = 5.0;
    double a = 0;
    double b = 100;
    double a0, b0, c;
    auto h = [f] (double x) {return f(x) - 5;};
    
    cout.precision(12);

    for (int i = 0; i < max_iter; i++) {
        a0 = a;
        b0 = b;
        c = (a + b) / 2;
        if (h(a) * h(c) < 0)
            b = c;
        if (h(b) * h(c) < 0)
            a = c;

        if (print_iteration) {
            cout << "Iteration " << i + 1 << ":" << endl;
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "c = " << c << endl;
            cout << "f(c) = " << f(c) << endl;
        }
        if (abs(a - b) < eps || abs(h(c)) < eps)
            break;
    }
    
    cout << "c = " << c << endl;
    cout << "f(c) = " << f(c) << endl;

    
    return 0;
}

