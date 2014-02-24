/* 
 * File:   w6e4.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <matutl02.h>
#include <myplot.h>
#include <solve.h>
#include "nr.h"

using namespace std;

Vec_DP coeff;

double eval(double x) {
    double a = coeff[0];
    double b = coeff[1] * x + coeff[3];
    double c = -x * x + coeff[2] * x + coeff[4];
    return (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
}

Vec_DP solve(Vec_DP const& xdata, Vec_DP const& ydata) {
    Mat_DP a(xdata.size(), 5);
    Vec_DP b(xdata.size()), x(5);
    for (int i = 0; i < xdata.size(); i++) {
        b[i] = xdata[i] * xdata[i];
        a[i][0] = ydata[i] * ydata[i];
        a[i][1] = xdata[i] * ydata[i];
        a[i][2] = xdata[i];
        a[i][3] = ydata[i];
        a[i][4] = 1;
    }
    SVDsolve(a, b, x);
    return x;
}

int main() {

    Mat_DP data = getmat("data/e4.txt");
    Vec_DP x(data.ncols()), y(data.ncols());
    for (int i = 0; i < data.ncols(); i++) {
        x[i] = data[0][i];
        y[i] = data[1][i];
    }

    coeff = solve(x, y);


    /*
     * Plotting
     */
    myplot::plot_data p("rx"), fit("b-");
    for (int i = 0; i < x.size(); i++) {
        p.add_point(x[i], y[i]);
    }

    int points = 200;
    double minx = -.2;
    double maxx = 1.1;
    double dx = (maxx - minx) / (points - 1);
    for (double xx = minx; xx <= maxx; xx += dx) {
        fit.add_point(xx, eval(xx));
    }
    myplot::plot({p, fit});

    return 0;
}

