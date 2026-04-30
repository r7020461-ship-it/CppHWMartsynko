#include <iostream>
#include <cmath>
using namespace std;

double sigmweight(double x) {
    return x * (1.0 / (1.0 + exp(-x)));
}

double sigmweight_derivative(double x) {
    double s = 1.0 / (1.0 + exp(-x));
    return s + x * s * (1.0 - s);
}

int main() {
    double x;
    cin >> x;

    cout << "f(x) = " << sigmweight(x) << endl;
    cout << "f'(x) = " << sigmweight_derivative(x) << endl;

    return 0;
}