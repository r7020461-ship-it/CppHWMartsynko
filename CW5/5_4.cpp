#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введіть n: ";
    cin >> n;

    double P = 1.0;
    for (int i = 1; i <= n; i++) {
        P *= (1.0 + 1.0 / i);
    }

    cout << "P_" << n << " = " << P << endl;

    return 0;
}
