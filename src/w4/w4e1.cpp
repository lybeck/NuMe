/* 
 * File:   w4e1.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "nr.h"
#include "matutl02.h"
#include "solve.h"
#include "myplot.h"

using namespace std;

typedef Vec_DP poly_coeffs;

double poly_val(poly_coeffs const& c, double x) {
    int n = c.size() - 1;
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += c[i] * pow(x, n - i);
    }
    return sum;
}

void plot_fit(vector<double> const& xdata, vector<double> const& ydata, poly_coeffs const& c) {
    if (xdata.size() != ydata.size()) {
        cout << "Data vectors must be of equal length in plot_fit!" << endl;
        throw exception();
    }

    int data_len = xdata.size();
    myplot::plot_data points("rx");
    double minx = INFINITY;
    double maxx = -INFINITY;
    for (int i = 0; i < data_len; i++) {
        points.add_point(xdata[i], ydata[i]);
        if (xdata[i] < minx)
            minx = xdata[i];
        if (xdata[i] > maxx)
            maxx = xdata[i];
    }

    // number of points
    int p = 200;
    minx -= 1;
    maxx += 1;
    double dx = (maxx - minx) / (p - 1);
    
    myplot::plot_data fit("b-");
    for (double x = minx; x <= maxx; x += dx) {
        fit.add_point(x, poly_val(c, x));
    }

    myplot::plot({points, fit});
}

poly_coeffs poly_fit(vector<double> const& x, vector<double> const& y, int n) {
    if (x.size() != y.size()) {
        cout << "Data vectors must be of equal length in polyfit!" << endl;
        throw exception();
    }
    int data_len = x.size();
    Mat_DP A(n + 1, n + 1);
    int n2 = 2 * n;
    for (int k = 0; k <= n2; k++) {
        int deg = n2 - k;
        if (deg == 0) {
            A[n][n] = data_len;
        } else {
            double sum = 0;
            for (int i = 0; i < data_len; i++) {
                sum += pow(x[i], deg);
            }
            int j;
            for (int i = max(0, k - n); i <= min(k, n); ++i) {
                j = k - i;
                A[i][j] = sum;
            }
        }
    }

    cout << endl << "A = " << endl << A << endl;

    Vec_DP b(n + 1);
    for (int i = 0; i <= n; i++) {
        int deg = n - i;
        double sum = 0;
        for (int i = 0; i < data_len; i++) {
            sum += pow(x[i], deg) * y[i];
        }
        b[i] = sum;
    }

    cout << "b = " << endl;
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << endl;
    }
    cout << endl;

    Vec_DP coeffs(n + 1);
    LUsolve(A, b, coeffs);
    return coeffs;
}

int main() {
    ifstream file("data/e1.txt");
    vector<double> x, y;
    string line;
    double temp;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> temp;
        x.push_back(temp);
        ss >> temp;
        y.push_back(temp);
    }
    file.close();
    
    poly_coeffs c = poly_fit(x, y, 2);

    cout << fixed;
    cout << "Fit result:" << endl;
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << endl;
    }
    cout << endl;

    plot_fit(x, y, c);
}

