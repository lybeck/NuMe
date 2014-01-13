/* 
 * File:   lam.cpp
 * Author: Lasse Lybeck
 *
 * Created on January 4, 2014, 3:30 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void print_values(double (*f) (double)){
    for (int i = 0; i < 10; i++) {
        cout << "f(" << i << ") = " << f(i) << endl;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    print_values([] (double x) {return 2 * x + 1;});
    return 0;
}

