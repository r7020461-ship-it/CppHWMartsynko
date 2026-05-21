#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    double a = 0;
    for (int i = 1; i <= n; i++) {
        a = sqrt(2 + a);
    }

    double b = 0;
    for (int i = n; i >= 1; i--) {
        b = sqrt(3 * i + b);
    }

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}