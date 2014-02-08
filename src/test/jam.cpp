#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
#include <thread>
#include "nr.h"
#include "matutl02.cpp"

using namespace std;

void f() {
    int N = 10000;
    Mat_DP A(N, N);
    ranmat2(A, -N, N);
    Mat_DP invA(N, N);
    cout << "alloc done" << endl;
    invmat(A, invA);
}

int main() {
    
    thread t1(f);
    thread t2(f);
    t1.join();
    t2.join();
    
    return 0;
}

