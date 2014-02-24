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

double eval2(double x) {
    double a = coeff[0];
    double b = coeff[1] * x + coeff[3];
    double c = -x * x + coeff[2] * x + coeff[4];
    return (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
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

double get_min_x() {
    double a = coeff[0];
    double b = coeff[1];
    double c = coeff[2];
    double d = coeff[3];
    double e = coeff[4];
    return (2 * sqrt(a * (a * c * c + 4 * a * e + b * b * e - b * c * d - d * d)) + 2 * a * c - b * d) / (4 * a + b * b);
}

double get_max_x() {
    double a = coeff[0];
    double b = coeff[1];
    double c = coeff[2];
    double d = coeff[3];
    double e = coeff[4];
    return (-2 * sqrt(a * (a * c * c + 4 * a * e + b * b * e - b * c * d - d * d)) + 2 * a * c - b * d) / (4 * a + b * b);
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
    myplot::plot_data p("rx"), fit("b-"), fit2("b-");
    for (int i = 0; i < x.size(); i++) {
        p.add_point(x[i], y[i]);
    }

    int points = 300;
    double minx = get_min_x();
    double maxx = get_max_x();
    double dx = (maxx - minx) / (points - 1);
    for (int i = 0; i < points; i++) {
        double xx = minx + i * dx;
        fit.add_point(xx, eval(xx));
        fit2.add_point(xx, eval2(xx));
    }
    myplot::plot({p, fit, fit2});

    return 0;
}

