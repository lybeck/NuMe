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
#include "nr.h"
#include "matutl02.h"

using namespace std;

void Jacobi_iter(Mat_DP &a, Vec_DP &b,
        Vec_DP &x, Vec_DP &xold) {
    DP s;
    int i, j, ma = a.nrows();
    if ((ma != a.ncols()) || (ma != b.size()) ||
            (ma != x.size()) || (ma != xold.size())) {
        cout << "Argument error in Jacobi_iter\n" << endl;
        abort();
    }
    for (i = 0; i < ma; i++) { /* This is Jacobi iteration */
        s = 0.0;
        for (j = 0; j < ma; j++)
            if (i != j) s += a[i][j] * xold[j];
        xold[i] = x[i];
        x[i] = (b[i] - s) / a[i][i];
    }
}

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

int main() {
    int ma;
    int i, j, k, ikind, ikindold, new1;
    ma = 6;
    Mat_DP a(ma, ma);
    Vec_DP b(ma), x(ma), xold(ma), sol(ma);
    DP er, s;
    init_srand();
    /* Give some values for a and b */
    ranmat2(a, -0.99, 0.99);
    for (i = 0; i < ma; i++)
        for (j = 0; j < ma; j++)
            a[i][j] = ceil(10 * a[i][j]);
    /* We give integer values for the entries of a */
    for (i = 0; i < ma; i++) {
        s = 0.0;
        for (j = 0; j < ma; j++) if (j != i) s = s + fabs(a[i][j]);
        if (fabs(a[i][i]) < s) a[i][i] = s + ma / 2;
    }
    /* Diag. entries are increased a bit, to ensure
    convergence of the iteration */
    cout << "Matrix a =" << endl;
    showmat2(a, "% 10.5f ");
    /* We make a solution in integer components */
    for (i = 0; i < ma; i++) sol[i] = (int) (ma / 2) - i;
    /* and, the corresponding RHS: */
    matvecmul(a, sol, b);
    for (i = 0; i < ma; i++) {
        x[i] = 0.0;
        xold[i] = 0.0;
    }
    new1 = 0;
    ikind = 0;
    do {
        ikindold = ikind;
        printf("Enter iteration: (1) Jacobi, (2) Gauss-Seidel \n");
        scanf("%d", &ikind);
        printf("\n ***\n ikind = %d \n", ikind);
        for (i = 0; i < ma; i++) printf("x[ % d]",i);
                printf("\n");
                /* Restart with x=0 if ikind !=ikindold */
            if (ikind != ikindold)
                for (i = 0; i < ma; i++) {
                    x[i] = 0.0; xold[i] = 0.0;
                }
        printf("\n 1 :");
        for (i = 0; i < ma; i++) printf(" %9.6f", x[i]);
                printf("\n");
            for (k = 1; k <= 40; k++) {
                if (ikind == 1) Jacobi_iter(a, b, x, xold);
                    if (ikind == 2) GaussSeidel_iter(a, b, x, xold);
                        if (k == 5 * ((int) (k / 5))) {
                            printf("%2d :", k);
                            for (i = 0; i < ma; i++) printf(" %9.6f", x[i]);
                            }
            }
        for (i = 0; i < ma; i++) printf(" %12.9f", x[i]);
                s = residual(a, x, b);
                printf("\nResidual = %12.4e \n", s);
                printf("Enter 0 if iterate again: \n");
                scanf("%ld", &new1);
        } while (new1 == 0);
            return 0;
        }