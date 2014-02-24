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

void draw_2nd_der(func f, double minx, double maxx) {
    double h = 1e-5;
    double a = minx - 2 * h;
    double b = maxx + 2 * h;
    int points = 200;
    double dx = (maxx - minx) / (points - 1);

    myplot::plot_data function_points("b-2"), der2_points("r-");
    for (double x = minx; x <= maxx; x += dx) {
        function_points.add_point(x, f(x));
        der2_points.add_point(x, numdf(f, a, b, x, h, 2));
    }
    myplot::plot({function_points, der2_points});
}

void draw_2nd_der_sum(func f, double minx, double maxx) {
    double h = 1e-5;
    double a = minx - 2 * h;
    double b = maxx + 2 * h;
    int points = 200;
    double dx = (maxx - minx) / (points - 1);

    myplot::plot_data function_points("b-2");
    for (double x = minx; x <= maxx; x += dx) {
        function_points.add_point(x, f(x) + numdf(f, a, b, x, h, 2));
    }
    myplot::plot({function_points});
}

int main() {

    draw_2nd_der([] (double x) {
        return pow(x, 3);
    }, -3, 3);
    draw_2nd_der_sum(sin, -M_PI, M_PI);

    return 0;
}

