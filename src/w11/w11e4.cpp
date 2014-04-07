/*
 * File:   w11e4.cpp
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
        if (v[i] == 0.0)
            cout << "0" << endl;
        else
            cout << v[i] << endl;
    }
    cout << endl;
}

int main() {

    Mat_DP A;
    Vec_DP b;
    int n;

    /*
     * Exc 4a
     */
    A = getmat("data/e4a-A.dat");
    b = getvec("data/e4a-b.dat");

    n = b.size();
    Vec_DP xa(n);

    LUsolve(A, b, xa);

    cout << endl << "xa = " << endl;
    printvec(xa);


    /*
     * Exc 4b
     */
    A = getmat("data/e4b-A.dat");
    b = getvec("data/e4b-b.dat");

    n = b.size();
    Vec_DP xb(n);

    LUsolve(A, b, xb);

    cout << endl << "xb = " << endl;
    printvec(xb);

    return 0;
}

