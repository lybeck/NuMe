/* 
 * File:   w5e4.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include "nr.h"
#include "matutl02.h"
#include "myplot.h"
#include "numdiff.h"
#include "eps.h"

using namespace std;

typedef double (*func) (double);

double der2(func f, double h, double x0) {
    Vec_DP y(6), dy(6), ddy(6);
    int i;
    for (i = 1; i <= 5; i++) {
        y[i] = f(x0 + (i - 3) * h);
    }
    numder(y, dy, h, 5);
    numder(dy, ddy, h, 5);
    return ddy[3];
}

void draw_2nd_der(func f, double minx, double maxx) {
    double h = 1e-5;
    int points = 200;
    double dx = (maxx - minx) / (points - 1);

    myplot::plot_data function_points("b-2"), der2_points("r-");
    for (double x = minx; x <= maxx; x += dx) {
        function_points.add_point(x, f(x));
        der2_points.add_point(x, der2(f, h, x));
    }
    myplot::plot({function_points, der2_points});
}

void draw_2nd_der_sum(func f, double minx, double maxx) {
    double h = 1e-5;
    int points = 200;
    double dx = (maxx - minx) / (points - 1);

    myplot::plot_data function_points("b-2");
    for (double x = minx; x <= maxx; x += dx) {
        function_points.add_point(x, f(x) + der2(f, h, x));
    }
    myplot::plot({function_points});
}

int main() {

    draw_2nd_der([] (double x) {return pow(x, 3);}, -3, 3);
    draw_2nd_der_sum(sin, -M_PI, M_PI);

    return 0;
}

