/* 
 * File:   w3e4.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <vector>
#include <matutl02.h>
#include "myplot.h"

//#define RANDOM_SEQUENCE

using namespace std;

typedef vector<double> sequence;

const double MAX_VAL = 10;

#ifdef RANDOM_SEQUENCE

void generate_vietoris_sequence(sequence& a) {
    if (a.empty())
        return;
    a[0] = rdm(0, MAX_VAL);
    if (a.size() < 2)
        return;
    a[1] = rdm(0, a[0]);
    for (int k = 2; k < a.size(); k++) {
        a[k] = rdm(0, (1.0 * k - 1) / k) * a[k - 1];
    }
}
#else

void generate_vietoris_sequence(sequence& a) {
    if (a.empty())
        return;
    a[0] = 1;
    if (a.size() < 2)
        return;
    a[1] = .5;
    for (int k = 2; k < a.size(); k++) {
        a[k] = a[k - 1] * (k - 1) / k;
    }
}
#endif

double f1(double x, sequence a) {
    double sum = 0;
    for (int i = 1; i < a.size(); i++) {
        sum += a[i] * sin(i * x);
    }
}

double f2(double x, sequence a) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * cos(i * x);
    }
}

int main() {

    init_srand();

    sequence a(256);

    generate_vietoris_sequence(a);

    int points = 200;
    double xmin = 0;
    double xmax = M_PI;
    double dx = (xmax - xmin) / (points - 1);
    myplot::plot_data d1("b-"), d2("r-");
    for (double x = xmin; x < xmax; x += dx) {
        d1.add_point(x, f1(x, a));
        d2.add_point(x, f2(x, a));
    }
    myplot::plot({d1, d2});

    return 0;
}

