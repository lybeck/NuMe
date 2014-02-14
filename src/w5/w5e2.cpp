/* 
 * File:   w5e2.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include "nr.h"
#include "matutl02.h"
#include "myplot.h"

using namespace std;

void run_interp(Vec_DP const& x, Vec_DP const& y) {
    Vec_DP xint(5), yint(5), err(5);
    cout << endl << "Interpolations:" << endl;
    cout << left;
    cout << endl << setw(10) << "x" << setw(15) << "f(x)" << setw(15) << "error est" << endl;
    for (int i = 0; i < xint.size(); i++) {
        xint[i] = 2 + i * .25;
        NR::polint(x, y, xint[i], yint[i], err[i]);
        cout << setw(10) << xint[i] << setw(15) << yint[i] << setw(15) << err[i] << endl;
    }

    myplot::plot_data data("rx"), interp("b.");
    for (int i = 0; i < x.size(); i++) {
        data.add_point(x[i], y[i]);
    }
    for (int i = 0; i < xint.size(); i++) {
        interp.add_point(xint[i], yint[i]);
    }
    myplot::plot({data, interp});
}

void run_static() {
    Vec_DP x(4), y(4);
    for (int i = 0; i < 4; i++) {
        x[i] = i + 1;
    }
    y[0] = 1;
    y[1] = 125;
    y[2] = 729;
    y[3] = 2197;

    run_interp(x, y);
}

void run_random() {
    init_srand();
    Vec_DP x(4), y(4);
    for (int i = 0; i < 4; i++) {
        x[i] = i + 1;
        y[i] = rdm(-10, 10);
    }

    run_interp(x, y);
}

int main() {

    run_static();
    run_random();

    return 0;
}

