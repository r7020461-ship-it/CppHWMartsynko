#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << "Number\tSqrt" << endl;

    for (int i = 1; i <= n; i++) {
        double r = sqrt(i);

        cout << i << "\t";

        // якщо корінь цілий — без дробової частини
        if (floor(r) == r) {
            cout << fixed << setprecision(0) << r;
        } else {
            cout << fixed << setprecision(2) << r;
        }

        cout << endl;
    }

    return 0;
}