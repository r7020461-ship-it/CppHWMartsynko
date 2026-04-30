#include <iostream>
#include <cmath>
using namespace std;

double f(double x, int n) {
    double y = x;

    for (int i = 0; i < n; i++) {
        y = sin(y);
    }

    return y;
}

int main() {
    double x;
    int n;

    cin >> x >> n;

    double y = f(x, n);

    cout << "y = " << y << endl;

    return 0;
}
