/* 
 * File:   eps.cpp
 * Author: Lasse Lybeck
 *
 * Created on January 14, 2014, 10:17 AM
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

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "machine epsilon = " << get_machine_epsilon() << endl;
    return 0;
}

