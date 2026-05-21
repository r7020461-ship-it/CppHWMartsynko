#include <iostream>
using namespace std;

double a(double x) {
    return (x * x + 2) * x * x + 1;
}

double b(double x) {
    return (((x + 1) * x + 1) * x + 1) * x + 1;
}

double v(double x) {
    return (((((x + 5) * x + 10) * x + 10) * x + 5) * x + 1);
}

double g(double x) {
    double x3 = x * x * x;
    return x3 * x3 * x3 + x3 + 1;
}

double d(double x) {
    return (((16 * x + 8) * x + 4) * x + 2) * x + 1;
}

double e(double x) {
    double x2 = x * x;
    return x * (x2 * x2 + x2 + 1);
}

int main() {
    double x;
    cin >> x;

    cout << "a) " << a(x) << endl;
    cout << "b) " << b(x) << endl;
    cout << "v) " << v(x) << endl;
    cout << "g) " << g(x) << endl;
    cout << "d) " << d(x) << endl;
    cout << "e) " << e(x) << endl;

    return 0;
}