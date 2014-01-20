/* 
 * File:   w1e4.cpp
 * Author: Lasse Lybeck
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <sstream>
#include <functional>
#include <vector>
#include <gsl/gsl_fit.h>
#include "plot.h"

using namespace std;

/*
 * Calculates the dot product between x and y. The function assumes that x and y have the same length.
 */
double dot(const vector<double> x, const vector<double> y) {
    double sum = 0;
    for (int i = 0; i < x.size(); i++) {
        sum += x[i] * y[i];
    }
    return sum;
}

/*
 * Calculates the sum of the elements in vector x.
 */
double sum(const vector<double> x) {
    double sum = 0;
    for (int i = 0; i < x.size(); i++) {
        sum += x[i];
    }
    return sum;
}

/*
 * Calculates the arithmetic mean of the elements in vector x.
 */
double mean(const vector<double> x) {
    return sum(x) / x.size();
}

vector<double> square_diff(const vector<double> x, double a) {
    vector<double> v(x.size());
    for (int i = 0; i < x.size(); i++) {
        v[i] = pow(x[i] - a, 2);
    }
    return v;
}

void linear_fit(const vector<double> x, const vector<double> y, double* a, double* b) {
    int n = x.size();
    double sumx = sum(x);
    double sumy = sum(y);
    *a = (dot(x, y) - sumx * sumy / n) / sum(square_diff(x, mean(x)));
    *b = (sumy - (*a) * sumx) / n;
}

void linear_fit_gsl(const vector<double> x, const vector<double> y, double* a, double* b) {
    int n = x.size();
    double cov00, cov01, cov11, chisq;
    gsl_fit_linear(&x[0], 1, &y[0], 1, n, b, a, &cov00, &cov01, &cov11, &chisq);
}

void plot_line(vector<double> x, vector<double> y, double a, double b) {
    const char* filename1 = "data1.tmp";
    const char* filename2 = "data2.tmp";
    ofstream file1(filename1);
    ofstream file2(filename2);
    
    for (int i = 0; i < x.size(); i++) {
        file1 << x[i] << " " << y[i] << "\n";
    }
    
    int points = 200;
    double xmin = x[0] - 1;
    double xmax = x[x.size() - 1] + 1;
    double dx = (xmax - xmin) / (points - 1);
    
    for (double i = xmin; i <= xmax; i += dx) {
        file2 << i << " " << (a * i + b) << "\n";
    }
    
    file1.close();
    file2.close();
    
    plot(filename1, "rx", filename2, "b-", NULL);
}

int main() {
    ifstream fin("rates.dat");
    vector<double> dates, values;
    double d, v;
    string s;

    while (getline(fin, s)) {
        istringstream sin(s);
        sin >> d;
        dates.push_back(d);
        sin >> v;
        values.push_back(v);
    }
    
    fin.close();
    
    double a, b;
    
    linear_fit(dates, values, &a, &b);
    cout << "With own implementation:" << endl;
    printf("Y = %f * X + %f\n", a, b);
    
    linear_fit_gsl(dates, values, &a, &b);
    cout << "With GSL implementation:" << endl;
    printf("Y = %f * X + %f\n", a, b);

    plot_line(dates, values, a, b);
    
    return 0;
}

