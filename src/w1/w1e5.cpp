/* 
 * File:   w1e5.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <gsl/gsl_precision.h>
#include <cmath>

const double EPS = gsl_prec_sqrt_eps[0];
const double max_iter = 50;

using namespace std;

double fixed_point_iteration(double (*f)(double), double x0) {
    double x = x0;
    double oldx;
    for (int i = 1; i <= max_iter; i++) {
        oldx = x;
        x = f(x);
        if(abs(x - oldx) < EPS)
            break;
        if(i == max_iter)
            cout << "WARNING! Maximum number of iterations reached in fixed point iteration,"
                    " the iteration might not have converged!" << endl;
    }
    return x;
}

int main() {

    double a = fixed_point_iteration(&cos, 0);
    double b = fixed_point_iteration([] (double x) {return exp(-x);}, 0);
    double c = fixed_point_iteration([] (double x) {return 1 - cosh(x);}, 0);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}

