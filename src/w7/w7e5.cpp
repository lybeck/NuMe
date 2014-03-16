/*
 * File:   w7e5.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <matutl02.h>
#include <solve.h>
#include <myplot.h>
#include "nr.h"

using namespace std;

Vec_DP coef;

Vec_DP solve(Vec_DP const& xdata, Vec_DP const& ydata, Vec_DP const& zdata) {
    Mat_DP a(xdata.size(), 3);
    Vec_DP b(zdata), x(3);
    for (int i = 0; i < xdata.size(); i++) {
        a[i][0] = xdata[i];
        a[i][1] = ydata[i];
        a[i][2] = 1;
    }
    SVDsolve(a, b, x);
    return x;
}

int main() {

    Mat_DP data = getmat("data/h075.dat");
    Vec_DP x(data.nrows()), y(data.nrows()), z(data.nrows());
    for (int i = 0; i < data.nrows(); i++) {
        x[i] = data[i][0];
        y[i] = data[i][1];
        z[i] = data[i][2];
    }

    coef = solve(x, y, z);

    cout << "a = " << coef[0] << endl;
    cout << "b = " << coef[1] << endl;
    cout << "c = " << coef[2] << endl;


    /*
     * Plotting
     */

    auto f = [] (double x, double y) {
        return coef[0] * x + coef[1] * y + coef[2];
    };

    myplot::surf_data_set container;
    myplot::surf_data points("+"), fit("-");
    myplot::generate_data(f, container, fit, -10, 10, -10, 10);
    for (int i = 0; i < x.size(); i++) {
        points.add_point(x[i], y[i], z[i]);
    }
    container.push_back(points);
    myplot::surf(container, "");

    return 0;
}

