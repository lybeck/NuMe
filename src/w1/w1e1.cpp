/* 
 * File:   w1e1.cpp
 * Author: Lasse Lybeck
 *
 * Created on January 4, 2014, 2:36 PM
 */

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double wind_chill(double T, double V) {
    return .045 * (5.27 * sqrt(V) + 10.45 - .28 * V) * (T - 33) + 33;
}

int Prompt_TV() {
    double T, V;
    cout << "Enter temperature in Celsius:" << endl;
    cin >> T;
    cout << "Enter wind speed in km/h:" << endl;
    cin >> V;
    cout << "For T = " << T << ", V = " << V;
    cout << ", wind chill is: " << wind_chill(T, V) << endl;
    return 0;
}

int main() {
    double T, V;
    Prompt_TV();
    for (int k = 0; k < 6; k++) printf("%5d ", k * 5);
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            T = 5.0 - i * 5.0;
            V = j * 5.0;
            double WC = wind_chill(T, V);
            if (j == 0) printf("\n% 5d ", (int) T);
            else
                printf("% 5d ", (int) WC);
        }
    printf("\n");
}

