
#include <iostream>
using namespace std;

int main() {
    double x, y = 1, term = 1;
    int n;

    cin >> x >> n;

    for (int i = 1; i <= n; i++) {
        term = term * x / i;
        y += term;
    }

    cout << "y = " << y << endl;

    return 0;
}