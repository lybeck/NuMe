/* 
 * File:   vectest.cpp
 * Author: Lasse Lybeck
 *
 * Created on January 8, 2014, 12:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Insert integers, end with 0." << endl;
    vector<int> v;
    int i;
    do {
        cin >> i;
        if (i)
            v.push_back(i);
    } while (i);
    cout << "You entered:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}

