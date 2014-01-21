/* 
 * File:   w2e2.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <vector>
#include "matutl02.h"
#include "plot.h"

using namespace std;

void plot_line(const vector<double> x, const vector<double> y, double a, double b) {
    const char* filename1 = "data1.tmp";
    const char* filename2 = "data2.tmp";
    ofstream file1(filename1);
    ofstream file2(filename2);

    for (int i = 0; i < x.size(); i++) {
        file1 << x[i] << " " << y[i] << "\n";
    }

    int points = 200;
    double xmin = x[0] - 1;
    double xmax = x[x.size() - 1] + 1;
    double dx = (xmax - xmin) / (points - 1);

    for (double i = xmin; i <= xmax; i += dx) {
        file2 << i << " " << (a * i + b) << "\n";
    }

    file1.close();
    file2.close();

    plot(filename1, "rx", filename2, "b-", NULL);
}

void plot_result(const Mat_DP& A, const Mat_DP& y, double a, double b) {
    
    vector<double> xdata(4);
    vector<double> ydata(4);
    for (int i = 0; i < xdata.size(); i++) {
        xdata[i] = A[i][0];
        ydata[i] = y[i][0];
    }
    
    plot_line(xdata, ydata, a, b);
}

/*
 * 
 */
int main() {
    
    Mat_DP A(1, 1);
    Mat_DP y(1, 1);
    A = getmat("e2/A.dat");
    y = getmat("e2/b.dat");

    // At= tranpose of A
    Mat_DP At = !A;

    // At * A
    Mat_DP AtA = At * A;

    // inv(At * A)
    Mat_DP invAtA(2, 2);
    invmat(AtA, invAtA);

    // inv(At * A) * A'
    Mat_DP invtimesAt = invAtA * At;

    // x = inv(At * A) * A' * y
    Mat_DP x = invtimesAt * y;
    
    double a = x[0][0];
    double b = x[1][0];
    
    // display the result
    cout << "y = " << a << " * x + " << b << endl;
    
    plot_result(A, y, a, b);
    
    return 0;
}

