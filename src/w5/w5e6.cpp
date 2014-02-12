/* 
 * File:   w5e6.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "nr.h"
#include "matutl02.h"
#include "myplot.h"
#include "solve.h"

using namespace std;

typedef Vec_DP poly_coeffs;

poly_coeffs polyfit_svd(vector<double> const& xdata, vector<double> const& ydata, int n) {
    if (xdata.size() != ydata.size())
        throw runtime_error("Data vectors must be of equal length in polyfit_svd!");
    if (n < 0)
        throw runtime_error("Degree of polynomial must be non-negative in polyfit_svd!");
    int k = xdata.size();
    Mat_DP A(k, n + 1);
    Vec_DP b(k), x(n + 1);
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = pow(xdata[i], j);
        }
        A[i][0] = 1;
        b[i] = ydata[i];
    }
    SVDsolve(A, b, x);
    return x;
}

void fit_poly(vector<double> const& xdata, vector<double> const& ydata) {
    poly_coeffs svd_c = polyfit_svd(xdata, ydata, 2);
    cout << endl << "With SVDsolve:" << endl;
    for (int i = 0; i < svd_c.size(); i++) {
        if (i != 0 && svd_c[i] >= 0)
            cout << "+";
        cout << svd_c[i] << " * x^" << i << "  ";
    }
    cout << endl << endl;
    
    
    /*
     * Plotting the result
     */
    double minx = 0;
    double maxx = 5;
    int points = 200;
    double dx = (maxx - minx) / (points - 1);
    myplot::plot_data svd_poly("b-"), data("rx");
    for (int i = 0; i < xdata.size(); i++) {
        data.add_point(xdata[i], ydata[i]);
    }
    for(double x = minx; x <= maxx; x += dx) {
        double y = svd_c[0];
        for (int n = 1; n < svd_c.size(); n++) {
            y += svd_c[n] * pow(x, n);
        }
        svd_poly.add_point(x, y);
    }
    myplot::plot({svd_poly, data});
}

int main() {

    vector<double> xdata = {1, 2, 3, 3, 4};
    vector<double> ydata = {2, 2, 3, 5, 6};

    fit_poly(xdata, ydata);

    return 0;
}

