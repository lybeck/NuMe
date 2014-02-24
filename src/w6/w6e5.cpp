/* 
 * File:   w6e5.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <numdiff.h>
#include <matutl02.h>
#include "nr.h"
#include "eps.h"
#include "myplot.h"

using namespace std;

typedef double (*func) (double);

double a1, a2, b1, b2;

double f(double x) {
    return a1 * sin(b1 * x) + a2 * cos(b2 * x);
}

double der(func f, double x) {
    double h = get_sqrt_machine_epsilon();
    Vec_DP y(6), dy(6);
    for (int i = 0; i < 6; i++) {
        y[i] = f(x + (i - 3) * h);
    }
    numder(y, dy, h, 5);
    return dy[3];
}

void plot_fun(func f, double minx, double maxx) {
    int points = 200;
    double dx = (maxx - minx) / (points - 1);
    myplot::plot_data fun("b-", "Function"), df("r-", "Derivative"), F("g-", "Integral");
    for (double x = minx; x <= maxx; x += dx) {
        fun.add_point(x, f(x));
        df.add_point(x, der(f, x));
        F.add_point(x, NR::qsimp(f, 0, x));
    }
    myplot::plot({fun, df, F});
}

int main() {
    
//    func g = [] (double x) {return pow(x, 2);};
//    plot_fun(g, -4, 4);
    
    init_srand();
    
    a1 = rdm(-2, 2);
    a2 = rdm(-2, 2);
    b1 = rdm(-2, 2);
    b2 = rdm(-2, 2);
    
    plot_fun(&f, -M_PI, M_PI);
    
    return 0;
}

