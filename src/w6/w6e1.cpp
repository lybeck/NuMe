/* 
 * File:   w6e1.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include "matutl02.h"
#include "nr.h"
#include "eps.h"
#include "myeigen.h"

using namespace std;

bool is_sym(Mat_DP const& a) {
    if (a.nrows() != a.ncols())
        return false;
    double tol = get_sqrt_machine_epsilon();
    for (int i = 0; i < a.nrows(); i++) {
        for (int j = i + 1; j < a.ncols(); j++) {
            if (abs(a[i][j] - a[j][i]) > tol) {
                return false;
            }
        }
    }
    return true;
}

bool is_pos_def(Mat_DP const& a) {
    Mat_DP tmp(a);
    if (!is_sym(tmp))
        return false;
    Vec_CPLX_DP e(tmp.nrows());
    myeigen(tmp, e);
    cout << "Eigenvalues:" << endl;
    for (int i = 0; i < e.size(); i++) {
        cout << e[i] << endl;
        if (e[i].real() <= 0)
            return false;
    }
    return true;
}

int main() {

    init_srand();
    int n = rdm(1, 10);
    int m = rdm(1, 10);

    Mat_DP a(n, m), at(m, n), q(m, m);
    ranmat2(a, -10, 10);
    transp(a, at);
    matmul(at, a, q);
    
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;
    cout << "q = " << endl << q << endl;

    bool p = is_pos_def(q);

    cout << "p = " << p << endl;

    return 0;
}
