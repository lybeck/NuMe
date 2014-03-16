/* 
 * File:   w7e1.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <matutl02.h>
#include <solve.h>
#include <myplot.h>
#include "nr.h"

using namespace std;

double m;

int main() {

    auto f = [] (double x) {
        return cos(M_PI * m * x);
    };

    auto integ = [] () {
        if (m == 0)
            return 1.0;
        return sin(M_PI * m) / (M_PI * m);
    };

    double minm = 0;
    double maxm = .5;
    int n = 30;
    double dm = (maxm - minm) / (n);
    
    myplot::plot_data tr("b-", "trap"), si("r-", "simp"), ro("g-", "romb"), ga("m-", "gaus");

    cout << endl;
    cout << left;
    cout << setw(10) << "m";
    cout << setw(14) << "trap";
    cout << setw(14) << "simp";
    cout << setw(14) << "romb";
    cout << setw(14) << "gaus";
    cout << endl;
    for (int i = 0; i <= n; i++) {
        m = i * dm;
        
        double truth = integ();
        double trap = abs(truth - NR::qtrap(f, 0, 1));
        double simp = abs(truth - NR::qsimp(f, 0, 1));
        double romb = abs(truth - NR::qromb(f, 0, 1));
        double gaus = abs(truth - NR::qgaus(f, 0, 1));
        
        cout << setw(10) << fixed << m;
        cout << scientific;
        cout << setw(14) << trap;
        cout << setw(14) << simp;
        cout << setw(14) << romb;
        cout << setw(14) << gaus;
        cout << endl;
        
        tr.add_point(m, trap);
        si.add_point(m, simp);
        ro.add_point(m, romb);
        ga.add_point(m, gaus);
    }
    cout << endl;
    
    myplot::plot({tr, si, ro, ga});

    return 0;
}

