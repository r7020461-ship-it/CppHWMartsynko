#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float a = 1e-4f;
    double b = 24.33e5;
    long double c = acos(-1.0L);   // π
    long double d = exp(1.0L);     // e
    long double e = sqrt(5.0L);    // √5
    long double f = log(100.0L);   // ln(100)

    cout << fixed << setprecision(2);

    cout << "10^-4 = " << a << endl;
    cout << "24.33E5 = " << b << endl;
    cout << "pi = " << c << endl;
    cout << "e = " << d << endl;
    cout << "sqrt(5) = " << e << endl;
    cout << "ln(100) = " << f << endl;

    return 0;
}