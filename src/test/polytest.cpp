

#include <iostream>
#include <vector>
#include "mypoly.h"

using namespace std;
using namespace mypoly;

int main() {

    vector<double> c({-1, 2.5, 3});
    vector<double> c2;

    poly f(c2);

    cout << "f = " << f << endl;
    cout << "f(0) = " << f(0) << endl;
    cout << "f(12) = " << f(12) << endl;

    return 0;
}

