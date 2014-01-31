/* 
 * File:   w3e3.cpp
 * Author: Lasse Lybeck
 */

#include <cmath>
#include <cstdlib>
#include <nr.h>
#include <matutl02.h>
#include "eps.h"

using namespace std;

const double MIN_VAL = -1e3;
const double MAX_VAL = 1e3;
const double MAX_FACTOR = 1e3;

void random_diagonally_dominant(Mat_DP& a) {
    for (int i = 0; i < a.nrows(); i++) {
        double sum = 0;
        for (int j = 0; j < a.ncols(); j++) {
            if (i != j) {
                a[i][j] = rdm(MIN_VAL, MAX_VAL);
                sum += abs(a[i][j]);
            }
        }
        a[i][i] = sum * rdm(1, MAX_FACTOR);
    }
}

bool is_diagonally_dominant(Mat_DP const& a) {
    for (int i = 0; i < a.nrows(); i++) {
        double sum = 0;
        for (int j = 0; j < a.ncols(); j++) {
            if (i != j) {
                sum += abs(a[i][j]);
            }
        }
        if (a[i][i] < sum)
            return false;
    }
    return true;
}

void run_multiplication_tests(int minn, int maxn, int times) {
    cout << endl << "Starting tests for the multiplication of two diagonally dominant matrices." << endl;

    int total_tests = (maxn - minn + 1) * times;
    int fails = 0;
    for (int i = minn; i <= maxn; i++) {
        Mat_DP a(i, i), b(i, i), prod(i, i);
        for (int j = 0; j < times; j++) {
            random_diagonally_dominant(a);
            random_diagonally_dominant(b);
            matmul(a, b, prod);
            if (!is_diagonally_dominant(prod))
                ++fails;
        }
    }

    cout << "Results:" << endl;
    cout << "Total tests = " << total_tests << endl;
    cout << "Fails = " << fails << endl;
    cout << "Ratio = " << 100.0 * fails / total_tests << " %" << endl << endl;
}

void run_inverse_tests(int minn, int maxn, int times) {
    cout << endl << "Starting tests for the inverse of a diagonally dominant matrices." << endl;

    int total_tests = (maxn - minn + 1) * times;
    int fails = 0;
    for (int i = minn; i <= maxn; i++) {
        Mat_DP a(i, i), inva(i, i);
        for (int j = 0; j < times; j++) {
            random_diagonally_dominant(a);
            invmat(a, inva);
            if (!is_diagonally_dominant(inva))
                ++fails;
        }
    }

    cout << "Results:" << endl;
    cout << "Total tests = " << total_tests << endl;
    cout << "Fails = " << fails << endl;
    cout << "Ratio = " << 100.0 * fails / total_tests << " %" << endl << endl;
}

void run_tests(int minn, int maxn, int times) {
    run_multiplication_tests(minn, maxn, times);
    run_inverse_tests(minn, maxn, times);
}

int main() {

    init_srand();

    run_tests(2, 50, 200);

    return 0;
}

