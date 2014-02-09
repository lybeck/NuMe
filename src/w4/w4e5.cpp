/* 
 * File:   w4e5.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include "nr.h"
#include "matutl02.h"

using namespace std;

void eigen(Mat_DP a, Vec_CPLX_DP &w) {
    NR::balanc(a);
    NR::elmhes(a);
    NR::hqr(a, w);
}

int main() {
    Mat_DP a(5, 5);
    ranmat2(a, -10, 10);
    cout << a << endl;
    
    Vec_CPLX_DP eig(5);
    eigen(a, eig);
    
    complex<double> sum(0, 0);
    for (int i = 0; i < eig.size(); i++) {
        cout << eig[i] << endl;
        sum += eig[i];
    }
    return 0;
}

