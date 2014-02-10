/* 
 * File:   w4e3.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "solve.h"
#include "nr.h"
#include "matutl02.h"
#include "myplot.h"

using namespace std;

double c[4] = {-0.4, 0.6, -1.3, 2.0};
double d[4] = {0.5, 0.0, 1.2, -0.8};

void find_lsq_point(int k) {
    Mat_DP a(k, 2);
    Vec_DP b(k), x(2);
    for (int i = 0; i < k; i++) {
        a[i][0] = -c[i];
        a[i][1] = 1;
        b[i] = d[i];
    }
    SVDsolve(a, b, x);


    /*
     * Plot the solution
     */
    double minx = 0;
    double maxx = 1;
    int points = 200;
    double dx = (maxx - minx) / (points - 1);
    vector<myplot::plot_data> data;
    for (int i = 0; i < k; i++) {
        myplot::plot_data line("b-");
        for (double xx = minx; xx < maxx; xx += dx) {
            line.add_point(xx, c[i] * xx + d[i]);
        }
        data.push_back(line);
    }
    myplot::plot_data point("r.2");
    point.add_point(x[0], x[1]);
    data.push_back(point);
    
    myplot::plot(data);
}

int main() {
    for (int k = 2; k <= 4; k++) {
        find_lsq_point(k);
    }
    return 0;
}

