/* 
 * File:   eps.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>

using namespace std;

double get_machine_epsilon() {
    double eps = 1.0;
    while (eps / 2.0 + 1.0 != 1.0) {
        eps /= 2.0;
    }
    return eps;
}

int main() {
    cout << "machine epsilon = " << get_machine_epsilon() << endl;
    return 0;
}

