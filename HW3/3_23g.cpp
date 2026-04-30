#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

double sinc(double x) {
    if (x == 0)
        return 1;
    return sin(x) / x;
}

double sinc_derivative(double x) {
    if (x == 0)
        return 0;
    return (x * cos(x) - sin(x)) / (x * x);
}

int main() {
    double x;
    cin >> x;

    cout << "sinc(x) = " << sinc(x) << endl;
    cout << "sinc'(x) = " << sinc_derivative(x) << endl;

    return 0;
}