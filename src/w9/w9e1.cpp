/* 
 * File:   w9e1.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <solve.h>
#include <stdexcept>
#include "nr.h"
#include "matutl02.h"

using namespace std;

Vec_DP operator-(Vec_DP const& a, Vec_DP const& b) {
    if (a.size() != b.size())
        throw runtime_error("Dimensions mismatch in vector subtraction!");
    Vec_DP x(a.size());
    for (int i = 0; i < a.size(); i++) {
        x[i] = a[i] - b[i];
    }
    return x;
}

void hilb(Mat_DP& A) {
    for (int i = 0; i < A.nrows(); i++) {
        for (int j = 0; j < A.ncols(); j++) {
            A[i][j] = 1.0 / (i + j + 1);
        }
    }
}

void ones(Vec_DP& v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = 1;
    }
}

void run_hilb_tests() {
    for (int n = 5; n <= 20; n++) {
        
        cout << endl << "n = " << n << endl << endl;
        
        Mat_DP H(n, n);
        Vec_DP b(n), x(n), xtr(n);
        hilb(H);
        ones(b);
        
        SVDsolve(H, b, x);
        Vec_DP svd_diff = b - x;
        double svd_err = vnormp(svd_diff, 2);
        
        double besterr = INFINITY;
        double besteps;
        for (int p = 0; p <= 16; p++) {
            double eps = pow(10.0, -p);
            Vec_DP xx(n);
            SVDsolve2(H, b, xx, eps);
            Vec_DP diff = b - xx;
            double err = vnormp(diff, 2);
            cout << "eps = " << eps << endl;
            cout << "err = " << err << endl;
            if(err < besterr) {
                besterr = err;
                besteps = eps;
                xtr = xx;
            }
        }
        
        cout << "With svd solve:" << endl;
        cout << x;
        cout << "Error: " << svd_err << endl << endl;
        
        cout << "With truncated svd:" << endl;
        cout << "Best eps = " << besteps << endl;
        cout << xtr;
        cout << "Error: " << besterr << endl << endl;
        
    }
}

int main() {

    run_hilb_tests();

    return 0;
}
