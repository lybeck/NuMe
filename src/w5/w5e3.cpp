/* 
 * File:   w5e3.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include "nr.h"
#include "myplot.h"

using namespace std;

void plot_gamma(Vec_DP const& xdata, Vec_DP const& ydata, Vec_DP const& y2, double errx) {
    myplot::plot_data data("rx"), gamm("c-2"), spline("b-"), error("g-");
    for (int i = 0; i < xdata.size(); i++) {
        data.add_point(xdata[i], ydata[i]);
    }
    double minx = xdata[0] - .05;
    double maxx = xdata[xdata.size() - 1] + .05;
    int points = 200;
    double y;
    double dx = (maxx - minx) / (points - 1);
    for (double x = minx; x <= maxx; x += dx) {
        NR::splint(xdata, ydata, y2, x, y);
        spline.add_point(x, y);
        gamm.add_point(x, tgamma(x));
    }
    
    myplot::plot({data, gamm, spline});
}

int main() {
    
    int n = 20;
    Vec_DP xdata(n), ydata(n);
    
    for (int i = 0; i < n; i++) {
        xdata[i] = .5 + .1 * (i + 1);
        ydata[i] = tgamma(xdata[i]);
    }
    
    Vec_DP y2(n);
    double yp1 = -2.29428;
    double ypn = 0.934735;
    NR::spline(xdata, ydata, yp1, ypn, y2);
    
    double xmin = xdata[1];
    double xmax = xdata[n - 2];
    double dx = .1;
    
    double y, err, errx;
    double maxerr = -INFINITY;
    for (double x = xmin; x <= xmax; x += dx) {
        NR::splint(xdata, ydata, y2, x, y);
        err = abs(y - tgamma(x));
        if (err > maxerr) {
            maxerr = err;
            errx = x;
        }
    }
    
    cout << endl << "Maximum error: " << maxerr << ", at x = " << errx << endl;
    
    
    /*
     * Plotting
     */
    plot_gamma(xdata, ydata, y2, errx);
    
    return 0;
}

