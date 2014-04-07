/* 
 * File:   w9e4.cpp
 * Author: Lasse Lybeck
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "der.h"
#include "eps.h"
#include "nr.h"
#include "matutl02.h"

using namespace std;

typedef Vec_DP(*fun) (Vec_DP const&);

Vec_DP operator*(Mat_DP const& A, Vec_DP const& b) {
    if (A.ncols() != b.size())
        throw runtime_error("Dimensions mismatch in Mat_DP * Vec_DP.");
    Vec_DP ans(A.nrows());
    for (int i = 0; i < A.nrows(); i++) {
        ans[i] = 0;
        for (int j = 0; j < A.ncols(); j++) {
            ans[i] += A[i][j] * b[j];
        }
    }
    return ans;
}

void vecsub(Vec_DP const& a, Vec_DP const& b, Vec_DP& c) {
    if (a.size() != b.size() || a.size() != c.size())
        throw runtime_error("Dimensions mismatch in Vec_DP subtraction!");

    for (int i = 0; i < a.size(); i++) {
        c[i] = a[i] - b[i];
    }
}

Vec_DP operator-(Vec_DP const& a, Vec_DP const& b) {
    Vec_DP ans(a.size());
    vecsub(a, b, ans);
    return ans;
}

Vec_DP fa(Vec_DP const& x) {
    if (x.size() != 2)
        throw runtime_error("Wrong dimension in fa!");

    Vec_DP ans(2);
    ans[0] = 2 * pow(x[0] + x[1], 2) + pow(x[0] - x[1], 2) - 8;
    ans[1] = 5 * pow(x[0], 2) + pow(x[1] - 3, 2) - 9;
    return ans;
}

Vec_DP fb(Vec_DP const& x) {
    if (x.size() != 3)
        throw runtime_error("Wrong dimension in fa!");

    Vec_DP ans(3);
    ans[0] = 3 * x[0] - cos(x[1] * x[2]) - .5;
    ans[1] = pow(x[0], 2) - 81 * pow(x[1] + .1, 2) + sin(x[2]) + 10.6;
    ans[2] = exp(-x[0] * x[1]) + 20 * x[2] + (10 * M_PI - 3) / 3.0;
    return ans;
}

void newton_step(fun f, Vec_DP const& xold, Vec_DP& xnew) {
    int n = xold.size();
    Mat_DP J(n, n), Jinv(n, n);
    myder::jacobi(f, xold, J);
    invmat(J, Jinv);
    Vec_DP fx = f(xold);
    Vec_DP Jinvx = Jinv * fx;
    vecsub(xold, Jinvx, xnew);
}

Vec_DP newton(fun f, Vec_DP x0) {
    int max_iter = 100;
    double tol = get_sqrt_machine_epsilon();

    Vec_DP xnew(x0);
    for (int i = 0; i < max_iter; i++) {

        Vec_DP xold(xnew);

        newton_step(f, xold, xnew);

        Vec_DP diff = xnew - xold;
        if (vnormp(diff, 2) < tol) {
            return xnew;
        }
    }

    cout << "WARNING! Newton iteration did not converge." << endl;

    return xnew;
}

int main() {

    Vec_DP xa(2);
    xa[0] = 2;
    xa[1] = 0;
    Vec_DP x = newton(&fa, xa);

    cout << scientific;
    cout << endl;
    cout << "Excercise a:" << endl;
    cout << "x1 = " << x[0] << endl;
    cout << "x2 = " << x[1] << endl;
    Vec_DP fax = fa(x);
    cout << "norm(fa(x)) = " << vnormp(fax, 2.0) << endl << endl;

    Vec_DP xb(3);
    xb[0] = 3;
    xb[1] = 4;
    xb[2] = 5;
    x = newton(&fb, xb);

    cout << "Excercise b:" << endl;
    cout << "x1 = " << x[0] << endl;
    cout << "x2 = " << x[1] << endl;
    cout << "x3 = " << x[2] << endl;
    Vec_DP fbx = fb(x);
    cout << "norm(fb(x)) = " << vnormp(fbx, 2.0) << endl << endl;

    return 0;
}

