#include <iostream>
using namespace std;

int main() {
    double a;
    cin >> a;

    double sum = 0;
    int n = 0;

    while (sum <= a) {
        n++;
        sum += 1.0 / n;
    }

    cout << "Pershe chyslo > a: " << sum << endl;
    cout << "n = " << n << endl;

    return 0;
}
