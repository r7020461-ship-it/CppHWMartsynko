#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double x, y = 0;

    cin >> n >> x;

    for (int k = 1; k <= n; k++) {
        y += k * pow(x, k - 1);
    }

    cout << "y = " << y << endl;

    return 0;
}
