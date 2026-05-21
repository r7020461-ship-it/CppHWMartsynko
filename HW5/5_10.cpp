#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    double u0 = 0, u1 = 0;
    double v0 = 1, v1 = 1;

    if (n == 0 || n == 1) {
        cout << "v[" << n << "] = 1" << endl;
        return 0;
    }

    double ui, vi;

    for (int i = 2; i <= n; i++) {
        ui = (u1 - u0 * v1 - v0) / (1 + u1 * u1 + v1 * v1);
        vi = (u1 - v1) / (abs(u0 + v1) + 2);

        u0 = u1;
        u1 = ui;

        v0 = v1;
        v1 = vi;
    }

    cout << "v[" << n << "] = " << v1 << endl;

    return 0;
}
