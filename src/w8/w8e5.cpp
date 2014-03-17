/* 
 * File:   w8e5.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include "nr.h"

using namespace std;

double K(double x) {
    return NR::ellf(0.5 * M_PI, x);
}

double eps(double x) {
    return NR::elle(0.5 * M_PI, x);
}

double expr_a() {
    return .5 * NR::qgaus(&K, 0, 1);
}

double expr_b() {
    return -.5 + NR::qgaus(&eps, 0, 1);
}

double expr_c() {
    return NR::qgaus([] (double x) {return atan(x) / x;}, 0, 1);
}

int main() {

    cout << "expr_a = " << expr_a() << endl;
    cout << "expr_b = " << expr_b() << endl;
    cout << "expr_c = " << expr_c() << endl;

    return 0;
}

