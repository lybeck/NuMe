/* 
 * File:   w4e2.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <solve.h>
#include "nr.h"
#include "matutl02.h"

using namespace std;

void GaussSeidel_iter(Mat_DP &a, Vec_DP &b,
        Vec_DP &x, Vec_DP &xold) {
    DP s;
    int i, j, ma = a.nrows();
    if ((ma != a.ncols()) || (ma != b.size()) ||
            (ma != x.size()) || (ma != xold.size())) {
        cout << "Argument error in GaussSeidel_iter\n" << endl;
        abort();
    }
    for (i = 0; i < ma; i++) { /* This is Gauss-Seidel iteration */
        s = 0.0;
        for (j = 0; j < ma; j++) {
            if (j <= i - 1) s += a[i][j] * x[j];
            if (j >= i + 1) s += a[i][j] * xold[j];
        }
        xold[i] = x[i];
        x[i] = (b[i] - s) / a[i][i];
    }
}

void ranmat_diagdomi(Mat_DP& a, double min, double max, double fac) {
    double sum;
    for (int i = 0; i < a.nrows(); i++) {
        sum = 0;
        for (int j = 0; j < a.ncols(); j++) {
            if (i != j) {
                a[i][j] = rdm(min, max);
                sum += abs(a[i][j]);
            }
        }
        a[i][i] = sum * fac;
    }
}

void run_test(int m) {
    int max_iter = 50;

    Mat_DP a(m, m);
    Vec_DP b(m);
    ranmat_diagdomi(a, -10, 10, 1.1);
    ranvec(b, -10, 10);

    Vec_DP lux(m), x(m), oldx(m);

    LUsolve(a, b, lux);
    double lures = residual(a, lux, b);
    double gsres;

    for (int i = 0; i < m; i++) {
        oldx[i] = 1;
        x[i] = 1;
    }

    cout << endl << "m = " << m << endl << endl;

    printf("%-5s %-16s %-16s\n\n", "n", "resid/GS", "resid/LUsolve");
    for (int i = 1; i <= max_iter; i++) {
        GaussSeidel_iter(a, b, x, oldx);
        if (!(i % 5)) {
            gsres = residual(a, x, b);
            printf("%-5d %-16e %-16e\n", i, gsres, lures);
        }
        oldx = x;
    }
    cout << endl;
}

int main() {

    init_srand();

    for (int m = 5; m <= 125; m *= 5) {
        run_test(m);
    }
    return 0;
}