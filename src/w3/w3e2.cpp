/* 
 * File:   w3e2.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <matutl02.h>
#include "myplot.h"

using namespace std;

typedef vector<double> poly_coeffs;

const double MIN_C = -10;
const double MAX_C = 10;

double analytic_poly_integral(poly_coeffs const& c, double a, double b) {
    double sum = 0;
    for (int i = 0; i < c.size(); i++) {
        sum += c[i] / (i + 1) * (pow(b, i + 1) - pow(a, i + 1));
    }
    return sum;
}

double poly_eval(poly_coeffs const& c, double x) {
    double sum = 0;
    for (int i = 0; i < c.size(); i++) {
        sum += c[i] * pow(x, i);
    }
    return sum;
}

double trapz_poly_integral(poly_coeffs const& c, double a, double b, int n) {
    
    auto f = [c] (double x) {
        return poly_eval(c, x);
    };
    
    double h = (b - a) / n;
    double sum = 0;
    for (int k = 0; k <= n; k++) {
        // x_k = a + k * h
        sum += f(a + k * h);
    }
    return h * sum - h / 2 * (f(a) + f(b));
}

void rand_poly(poly_coeffs& c) {
    for (int i = 0; i < c.size(); i++) {
        c[i] = rdm(MIN_C, MAX_C);
    }
}

void print_poly(poly_coeffs const& c) {
    for (int i = 0; i < c.size(); i++) {
        if (i > 0)
            cout << (signbit(c[i]) ? " - " : " + ") << abs(c[i]);
        else
            cout << c[i];
        if (i > 0)
            cout << " * x";
        if (i > 1)
            cout << "^" << i;
    }
    cout << endl;
}

void run_comparison() {
    init_srand();
    poly_coeffs c(5);
    rand_poly(c);
    double a = -2;
    double b = 2;

    cout << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "poly = ";
    print_poly(c);
    cout << endl;

    double analytic = analytic_poly_integral(c, a, b);

    printf("Analytic integral = %-.12g\n\n", analytic);
    printf("%-8s %-14s %-20s %-15s\n", "n", "I(a,b,n)", "|I(a,b,n) - I(a,b)|", "h*h");
    for (int n = 10; n <= 1e6; n *= 10) {
        double numeric = trapz_poly_integral(c, a, b, n);
        double diff = abs(analytic - numeric);
        double h = (b - a) / n;
        printf("%-8d %-14.10g %-20e %-15e\n", n, numeric, diff, h * h);
    }
    cout << endl;


    // plotting the function
    myplot::plot_data data("r-2");
    int points = 200;
    double dx = (b - a) / (points - 1);
    for (double x = a; x <= b; x += dx) {
        data.add_point(x, poly_eval(c, x));
    }
    myplot::plot_data xaxis("k-4");
    xaxis.add_point(a, 0);
    xaxis.add_point(b, 0);
    myplot::plot_data yaxis(xaxis.get_style());
    yaxis.add_point(0, min(data.get_min_y(), 0.0));
    yaxis.add_point(0, max(data.get_max_y(), 0.0));
    myplot::plot({xaxis, yaxis, data});
}

int main() {
    run_comparison();
    return 0;
}

