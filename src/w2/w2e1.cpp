/* 
 * File:   w2e1.cpp
 * Author: Lasse Lybeck
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "matutl02.h"

using namespace std;

const double monte_carlo_points = 1e6;

bool is_between(double x, double y1, double y2) {
    return (x > y1 && x < y2) || (x < y1 && x > y2);
}

double monte_carlo_between_curves(double (*f) (double), double (*g) (double),
        double xmin, double xmax, double ymin, double ymax) {
    
    int hits = 0;
    double x, y;
    for (int i = 0; i < monte_carlo_points; i++) {
        x = rdm(xmin, xmax);
        y = rdm(ymin, ymax);
        if (is_between(y, f(x), g(x))) {
            ++hits;
        }
    }
    
    double area = (xmax - xmin) * (ymax - ymin);
    double ratio = (double) hits / monte_carlo_points;

    return ratio * area;
}

int main() {

    // seed the random
    init_srand();

    double d = monte_carlo_between_curves(&sin, &cos, 0, 2 * M_PI, -1, 1);
    
    cout << "Area between curves = " << d << endl;
}

