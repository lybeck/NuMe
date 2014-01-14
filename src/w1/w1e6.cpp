/* 
 * File:   w1e6.cpp
 * Author: Lasse Lybeck
 *
 * Created on January 13, 2014, 3:03 PM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <gsl/gsl_precision.h>
#include <gsl/gsl_sf_hyperg.h>
#include <cmath>

using namespace std;

const double eps = gsl_prec_sqrt_eps[0];
const int max_iter = 100;

double ag(double a, double b) {
    double oldA = a;
    double oldB = b;
    for (int i = 0; i < max_iter; i++) {
        a = (oldA + oldB) / 2;
        b = sqrt(oldA * oldB);
        if (abs(oldA - a) < eps)
            break;
        oldA = a;
        oldB = b;
    }
    return a;
}

double gauss(double r) {
    return 1 / ag(1, sqrt(1 - pow(r, 2)));
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    double lib, form;
    
    printf("%-7s %-15s %-15s %-15s\r\n", "r", "library func", "formula", "diff");
    for (int k = 1; k < 20; k++) {
        double r = 0.05 * k;
        lib = gsl_sf_hyperg_2F1(.5, .5, 1, pow(r, 2));
        form = gauss(r);
        printf("%-7.2f %-15.8f %-15.8f %-15e\r\n", r, lib, form, form - lib);
    }
    
    return 0;
}

