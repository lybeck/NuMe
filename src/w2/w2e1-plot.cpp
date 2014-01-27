/* 
 * File:   w2e1.cpp
 * Author: Lasse Lybeck
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "matutl02.h"
#include "plot.h"

using namespace std;

const double monte_carlo_points = 1000;
const char* point_hit_filename = "point_hit.tmp";
const char* point_miss_filename = "point_miss.tmp";
const char* f1_filename = "f1.tmp";
const char* f2_filename = "f2.tmp";

bool is_between(double x, double y1, double y2) {
    return (x > y1 && x < y2) || (x < y1 && x > y2);
}

double monte_carlo_between_curves(double (*f) (double), double (*g) (double), double xmin, double xmax, double ymin, double ymax) {
    
    ofstream p_hit_file(point_hit_filename);
    ofstream p_miss_file(point_miss_filename);
    
    int hits = 0;
    double x, y, fx, gx;
    for (int i = 0; i < monte_carlo_points; i++) {
        x = rdm(xmin, xmax);
        y = rdm(ymin, ymax);
        fx = f(x);
        gx = g(x);
        if (is_between(y, fx, gx)) {
            p_hit_file << x << " " << y << endl;
            ++hits;
        } else {
            p_miss_file << x << " " << y << endl;
        }
    }

    double area = (xmax - xmin) * (ymax - ymin);
    double ratio = (double) hits / monte_carlo_points;
    
    p_hit_file.close();
    p_miss_file.close();

    return ratio * area;
}

int main() {

    // seed the random
    init_srand();
    
    double minx = 0;
    double maxx = 2 * M_PI;

    double (*f1) (double) = &sin;
    double (*f2) (double) = &cos;

    double d = monte_carlo_between_curves(f1, f2, minx, maxx, -1, 1);

    cout << "Area between curves = " << d << endl;
    
    ofstream f1_file(f1_filename);
    ofstream f2_file(f2_filename);
    
    int points = 200;
    double dx = (maxx - minx) / (points - 1);
    
    for (double x = minx; x <= maxx; x += dx) {
        f1_file << x << " " << f1(x) << endl;
        f2_file << x << " " << f2(x) << endl;
    }
    
    f1_file.close();
    f2_file.close();
    
    plot(f1_filename, "k-5", f2_filename, "k-5", point_hit_filename, "b.", point_miss_filename, "r.", NULL);
}

