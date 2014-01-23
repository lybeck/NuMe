/* 
 * File:   eps.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cmath>
#include "eps.h"

double calculate_machine_epsilon();

const double eps = calculate_machine_epsilon();

double calculate_machine_epsilon() {
    double epsilon = 1.0;
    while (epsilon / 2.0 + 1.0 != 1.0) {
        epsilon /= 2.0;
    }
    return epsilon;
}

double get_machine_epsilon() {
    return eps;
}

double get_sqrt_machine_epsilon() {
    return sqrt(eps);
}

