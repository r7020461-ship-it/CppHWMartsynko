#include <iostream>
using namespace std;

double bn(double b, int n) {
    double r = b;
    for (int i = 2; i <= n; i++)
        r = b + 1.0 / r;
    return r;
}

double lambda(int n) {
    double r = 4 * n + 2;
    for (int k = n - 1; k >= 1; k--)
        r = 4 * k + 2 + 1.0 / r;
    return 2 + 1.0 / r;
}

double x2n(int n) {
    double r = 2; // останній знаменник

    for (int i = 2 * n - 1; i >= 1; i--) {
        if (i % 2 == 1)
            r = 1 + 1.0 / r;
        else
            r = 2 + 1.0 / r;
    }

    return r;
}

int main() {
    double b;
    int n;

    cin >> b >> n;

    cout << "a) b_n = " << bn(b, n) << endl;
    cout << "b) lambda_n = " << lambda(n) << endl;
    cout << "c) x_2n = " << x2n(n) << endl;

    return 0;
}