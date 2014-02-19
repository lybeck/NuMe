/* 
 * File:   w6e2.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include "nr.h"
#include "matutl02.h"
#include "solve.h"

using namespace std;

void print_vec(Vec_DP const& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << endl;
}

void pinv_solve(Mat_DP& a, Vec_DP& b, Vec_DP& x) {
    Mat_DP pinva(a.ncols(), a.nrows());
    pseudoinv(a, pinva);
    matvecmul(pinva, b, x);
}

int main() {
    
    Vec_DP b(3), x(3);
    for (int i = 0; i < b.size(); i++) {
        b[i] = i + 1;
    }
    
    Mat_DP a(3, 3);
    
    // exc a
    a = getmat("data/e2a.txt");
    pinv_solve(a, b, x);
    cout << endl << "Exc 2a solution:" << endl;
    print_vec(x);
    
    // exc b
    a = getmat("data/e2b.txt");
    pinv_solve(a, b, x);
    cout << "Exc 2b solution:" << endl;
    print_vec(x);
    
    return 0;
}

