#include <iostream>
#include <cmath>
using namespace std;

double expTaylor(double x, double eps) {
    double sum = 1;
    double term = 1;
    int n = 1;

    while (abs(term) > eps) {
        term *= x / n;
        sum += term;
        n++;
    }

    return sum;
}

double phiTaylor(double x, double eps) {
    double sum = 0;
    double term = x;
    int n = 0;

    while (abs(term) > eps) {
        sum += term;

        term *= (-1) * x * x * (2 * n + 1) /
                ((n + 1) * (2 * n + 3));
        n++;
    }

    return sum;
}

int main() {
    double x, eps;
    cin >> x >> eps;

    double e_res = expTaylor(x, eps);
    double e_math = exp(x);

    double phi_res = phiTaylor(x, eps);

    cout << "Taylor e^x = " << e_res << endl;
    cout << "Math exp(x) = " << e_math << endl;
    cout << "Difference = " << abs(e_res - e_math) << endl;

    cout << "Phi(x) Taylor = " << phi_res << endl;

    return 0;
}