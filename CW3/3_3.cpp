#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    char comma1, comma2;

    cin >> a >> comma1 >> b >> comma2 >> c;

    long long product = 1LL * a * b * c;

    if (abs(a) < pow(2, 10) && abs(b) < pow(2, 10) && abs(c) < pow(2, 10)) {
        cout << "a) product = " << product << endl;
    }

    if (abs(a) < pow(2, 21) && abs(b) < pow(2, 21) && abs(c) < pow(2, 21)) {
        cout << "b) product = " << product << endl;
    }

    return 0;
}