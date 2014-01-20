/* 
 * File:   w1e2.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

double wind_chill(double T, double V) {
    return .045 * (5.27 * sqrt(V) + 10.45 - .28 * V) * (T - 33) + 33;
}

int main() {
    for (int w = 0; w <= 4; w++) {
        int wind = 2 * w;
        printf("%10d", wind);
        for (int t = 0; t <= 4; t++) {
            int temp = 10 - 5 * t;
            if (w == 0)
                printf("%10d", temp);
            else
                printf("%10d", (int) wind_chill(temp, wind * 3.6));
        }
        cout << endl;
    }
    return 0;
}

