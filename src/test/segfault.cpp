#include <iostream>
#include <iomanip>
#include "nr.h"
#include "matutl02.cpp"

using namespace std;

void eigen(Mat_DP a, Vec_CPLX_DP &w) {
    NR::balanc(a);
    NR::elmhes(a);
    NR::hqr(a, w);
}

int main() {
    int n = 10;
    Mat_DP a(n, n);
    Vec_CPLX_DP eig(n);
    init_srand();
    ranmat2(a, -2.0, 2.0);
    eigen(a, eig);
    complex<double> sum(0.0, 0.0);
    for (int i = 0; i < n; i++) {
        sum += eig[i];
        cout << eig[i] << endl;
    }
    return 0;
}
