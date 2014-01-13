/* 
 * File:   w1e3.cpp
 * Author: Lasse Lybeck
 *
 * Created on January 8, 2014, 11:51 AM
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream fin("h013.dat");
    vector<double> x, y;
    double tmp;
    string s;

    // discard first line
    getline(fin, s);

    while (getline(fin, s)) {
        istringstream sin(s);
        sin >> tmp;
        x.push_back(tmp);
        sin >> tmp;
        y.push_back(tmp);
    }
    
    cout << "(x, y) pairs:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << ", " << y[i] << endl;
    }
    cout << endl;

    cout << "(x, y'(x)) pairs:" << endl;
    double x0, d;
    for (int i = 0; i < x.size() - 1; i++) {
        x0 = (x[i + 1] + x[i]) / 2;
        d = (x[i + 1] - x[i]) / (y[i + 1] - y[i]);
        cout << x0 << ", " << d << endl;
    }
    cout << endl;

    return 0;
}

