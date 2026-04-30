#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    double u0 = 0, u1 = 0;
    double v0 = 1, v1 = 1;

    if (n == 0 || n == 1) {
        cout << "v[" << n << "] = 1";
        return 0;
    }

    double u, v;

    for (int i = 2; i <= n; i++) {
        u = (u1 - u0 * v1 - v0) / (1 + u1 * u1 + v1 * v1);
        v = (u1 - v1) / (abs(u0 + v1) + 2);

        u0 = u1;
        u1 = u;

        v0 = v1;
        v1 = v;
    }

    cout << "v[" << n << "] = " << v1 << endl;

    return 0;
}