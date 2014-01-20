/* 
 * File:   w2e1.cpp
 * Author: Lasse Lybeck
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>

using namespace std;

const double monte_carlo_points = 1e6;

double rand_double() {
    return (double) rand() / RAND_MAX;
}

double rand_double(double min, double max) {
    return (max - min) * rand_double() + min;
}

bool is_between(double x, double y1, double y2) {
    return (x > y1 && x < y2) || (x < y1 && x > y2);
}

double monte_carlo_between_curves(double (*f) (double), double (*g) (double), double xmin, double xmax, double ymin, double ymax) {
    int hits = 0;
    double x, y, fx, gx;
    for (int i = 0; i < monte_carlo_points; i++) {
        x = rand_double(xmin, xmax);
        y = rand_double(xmin, xmax);
        fx = f(x);
        gx = g(x);
        if (is_between(y, fx, gx)) {
            ++hits;
        }
    }
    
    double area = (xmax - xmin) * (ymax - ymin);
    double ratio = (double) hits / monte_carlo_points;

    return ratio * area;
}

int main() {

    // seed the random
    srand(time(0));

    double d = monte_carlo_between_curves(&sin, &cos, 0, 2 * M_PI, -1, 1);
    
    cout << "d = " << d << endl;
}

