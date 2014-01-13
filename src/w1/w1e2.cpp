/* 
 * File:   w1e2.cpp
 * Author: Lasse Lybeck
 *
 * Created on January 7, 2014, 7:06 PM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

double wind_chill(double T, double V) {
    return .045 * (5.27 * sqrt(V) + 10.45 - .28 * V) * (T - 33) + 33;
}

/*
 * 
 */
int main(int argc, char** argv) {
    for (int w = 0; w <= 4; w++) {
        int wind = 2 * w;
        printf("%13d", wind);
        for (int t = 0; t <= 4; t++) {
            int temp = 10 - 5 * t;
            if (w == 0)
                printf("%13d", temp);
            else
                printf("%13f", wind_chill(temp, wind * 3.6));
        }
        cout << endl;
    }
    return 0;
}

