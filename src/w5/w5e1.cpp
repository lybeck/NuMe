/* 
 * File:   w5e1.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "nr.h"
#include "matutl02.h"
#include "myplot.h"

using namespace std;

void get_error(Vec_DP const& x, Vec_DP y, double& maxerr, double& errx) {
    maxerr = -INFINITY;
    double yy, err;
    for (int i = 0; i < x.size(); i++) {
        yy = sin(x[i]);
        err = abs(y[i] - yy);
        if (err > maxerr) {
            maxerr = err;
            errx = x[i];
        }
    }
}

void spline_interp(Vec_DP const& xdata, Vec_DP const& ydata, double yp1, double ypn, Vec_DP const& x, Vec_DP& y) {
    Vec_DP y2(xdata.size());
    NR::spline(xdata, ydata, yp1, ypn, y2);
    for (int i = 0; i < x.size(); i++) {
        NR::splint(xdata, ydata, y2, x[i], y[i]);
    }

    double err, errx;
    get_error(x, y, err, errx);

    cout << "Maximum error in spline interpolation: " << err << ", at x = " << errx << endl;
}

double poly_val(double x, Vec_DP const& c) {
    double y = c[0];
    for (int n = 1; n < c.size(); n++) {
        y += c[n] * pow(x, n);
    }
    return y;
}

void poly_interp(Vec_DP const& xdata, Vec_DP const& ydata, Vec_DP const& x, Vec_DP& y) {
    Vec_DP c(xdata.size());
    NR::polcoe(xdata, ydata, c);
    for (int i = 0; i < x.size(); i++) {
        y[i] = poly_val(x[i], c);
    }

    double err, errx;
    get_error(x, y, err, errx);

    cout << "Maximum error in polynomial interpolation: " << err << ", at x = " << errx << endl;
}

int main() {

    int N = 6;

    Vec_DP xdata(N), ydata(N);
    for (int k = 0; k <= N; k++) {
        xdata[k] = k * M_PI / 10;
        ydata[k] = sin(xdata[k]);
    }

    int points = 101;
    Vec_DP x(points);
    for (int k = 0; k <= 100; k++) {
        x[k] = k * M_PI / 200;
    }

    Vec_DP polyy(x.size());
    poly_interp(xdata, ydata, x, polyy);

    double yp1 = 1;
    double ypn = 0;
    Vec_DP spliney(x.size());
    spline_interp(xdata, ydata, yp1, ypn, x, spliney);

    myplot::plot_data data("rx");
    for (int i = 0; i < xdata.size(); i++) {
        data.add_point(xdata[i], ydata[i]);
    }

    myplot::plot_data poly("b-");
    for (int i = 0; i < x.size(); i++) {
        poly.add_point(x[i], polyy[i]);
    }

    myplot::plot_data spln("m-");
    for (int i = 0; i < x.size(); i++) {
        spln.add_point(x[i], spliney[i]);
    }

    myplot::plot({data, poly});

    myplot::plot({data, spln});

    return 0;
}

