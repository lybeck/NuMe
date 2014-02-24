/* 
 * File:   w6e3.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <solve.h>
#include <matutl02.h>
#include <myplot.h>
#include "nr.h"

using namespace std;

typedef Vec_DP quad_coeffs;

quad_coeffs coeff;

inline
double quad_eval(double x, double y) {
    return coeff[0] * x * x + coeff[1] * y * y + coeff[2] * x * y + coeff[3] * x + coeff[4] * y + coeff[5];
}

quad_coeffs quad_solve(Vec_DP const& xdata, Vec_DP const& ydata, Vec_DP const& zdata) {
    Mat_DP a(xdata.size(), 6);
    Vec_DP b(zdata), x(6);
    for (int i = 0; i < xdata.size(); i++) {
        a[i][0] = xdata[i] * xdata[i];
        a[i][1] = ydata[i] * ydata[i];
        a[i][2] = xdata[i] * ydata[i];
        a[i][3] = xdata[i];
        a[i][4] = ydata[i];
        a[i][5] = 1;
    }
    SVDsolve(a, b, x);
    return x;
}

void print_city(string city, double x, double y, double real, double est) {
    cout << setw(15) << city << setw(8) << x << setw(8) << y << setw(12) << real << setw(12) << est << endl;
}

int main() {

    Mat_DP a = getmat("data/e3.txt");
    Vec_DP x(a.nrows()), y(a.nrows()), z(a.nrows());
    for (int i = 0; i < a.nrows(); i++) {
        x[i] = a[i][0];
        y[i] = a[i][1];
        z[i] = a[i][2];
    }

    coeff = quad_solve(x, y, z);


    // print the results
    cout << left << fixed;
    cout.precision(2);

    double xcrd, ycrd;

    cout << endl;
    cout << setw(15) << "City" << setw(8) << "xcrd" << setw(8) << "ycrd" << setw(12) << "real temp" << setw(12) << "est temp" << endl;
    xcrd = 5.3;
    ycrd = 3.4;
    print_city("Jyvaskyla", xcrd, ycrd, .5, quad_eval(xcrd, ycrd));
    xcrd = 6.3;
    ycrd = 2.7;
    print_city("Mikkeli", xcrd, ycrd, 1.2, quad_eval(xcrd, ycrd));
    xcrd = 5.2;
    ycrd = 1.6;
    print_city("Lahti", xcrd, ycrd, .2, quad_eval(xcrd, ycrd));
    xcrd = 2.7;
    ycrd = 2.5;
    print_city("Pori", xcrd, ycrd, 1.3, quad_eval(xcrd, ycrd));
    xcrd = 6.4;
    ycrd = 4.2;
    print_city("Kuopio", xcrd, ycrd, .5, quad_eval(xcrd, ycrd));
    cout << endl;


    // plot
    myplot::surf_data_set container;
    myplot::surf_data surface("-");
    myplot::surf_data points("+");
    myplot::generate_data(quad_eval, container, surface, -1, 9, -1, 9);
    for (int i = 0; i < x.size(); i++) {
        points.add_point(x[i], y[i], z[i]);
    }
    container.push_back(points);
    myplot::surf(container, "");

    return 0;
}

