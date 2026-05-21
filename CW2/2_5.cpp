#include <iostream>
#include <cmath>
using namespace std;

double Rosenbrock2d(double x, double y) {
    return 100 * pow(x * x - y, 2) + pow(x - 1, 2);
}

int main() {
    double x, y;

    for (int i = 1; i <= 3; i++) {
        cin >> x >> y;
        cout << "Rosenbrock2d(" << x << ", " << y << ") = "
             << Rosenbrock2d(x, y) << endl;
    }

    return 0;
}