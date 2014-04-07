/*
 * File:   w11e2.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "nr.h"
#include "matutl02.h"
#include "eps.h"

using namespace std;

double f(Vec_DP const& v) {
    double x = v[0];
    double y = v[1];
    return 100 * pow((x * x - y), 2) + pow(1 - x, 2);
}

Vec_DP subst(Vec_DP const& w) {
    if (w.size() != 2)
        throw runtime_error("Wrong dimension for input in subst!");
    Vec_DP x(2);
    x[0] = -2 + 2.8 * pow(sin(w[0]), 2);
    x[1] = w[1];
    return x;
}

double g(Vec_DP const& x) {
    if (x.size() != 2)
        throw runtime_error("Wrong dimension for input in function g!");
    Vec_DP w = subst(x);
    return f(w);
}

int main() {

    double tol = get_sqrt_machine_epsilon();
    int tests = 20;

    double fret;
    int iter;
    double best_val = INFINITY;
    Mat_DP xi(2, 2);
    xi[0][0] = 1.0;
    xi[0][1] = 0.0;
    xi[1][0] = 0.0;
    xi[1][1] = 1.0;
    Vec_DP res(2), best(2);

    for (int i = 0; i < tests; i++) {
        // init guess
        res[0] = rdm(-10, 10);
        res[1] = rdm(-10, 10);

        NR::powell(res, xi, tol, iter, fret, g);

        Vec_DP x = subst(res);
        double val = f(x);

        if (val < best_val)
            best = x;
    }

    cout << endl << "Minimum found at (x,y) = (" << best[0] << ", " << best[1] << ")" << endl;
    cout << "f(x, y) = " << f(best) << endl << endl;

    return 0;
}

