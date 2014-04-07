/*
 * File:   w11e3.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <solve.h>
#include "nr.h"
#include "matutl02.h"
#include "eps.h"

using namespace std;

Vec_DP getvec(const char *fname) {
    Mat_DP a;
    a = getmat(fname);
    if (a.ncols() != 1)
        throw runtime_error("Error in getvec: not a vector!");
    int n = a.nrows();
    Vec_DP v(n);
    for (int i = 0; i < n; i++) {
        v[i] = a[i][0];
    }
    return v;
}

void printvec(Vec_DP const& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << endl;
}

int main() {

    Mat_DP A = getmat("data/e3-A.dat");
    Vec_DP b = getvec("data/e3-b.dat");

    int n = b.size();
    Vec_DP x(n);

    LUsolve(A, b, x);

    cout << endl << "x = " << endl;
    printvec(x);

    return 0;
}

