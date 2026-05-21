#include <iostream>
using namespace std;

int main() {
    int n = 3;
    long long x1 = -99, x2 = -99, x3 = -99;
    long long x = x3;

    while (x <= 0) {
        n++;
        x = x3 + x1 + 100; // x_n = x_{n-1} + x_{n-3} + 100

        x1 = x2;
        x2 = x3;
        x3 = x;
    }

    cout << "Naimenshyi dodatnyi chlen = " << x << endl;
    cout << "Yoho nomer = " << n << endl;

    return 0;
}