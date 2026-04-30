#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double x, sum = 0;

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        sum += i * pow(x, i);
    }

    cout << "S = " << sum << endl;

    return 0;
}