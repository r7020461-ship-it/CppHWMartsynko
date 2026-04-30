#include <iostream>
using namespace std;

int main() {
    double x;
    cin >> x;

    double x2 = x * x;          // 1
    double x4 = x2 * x2;        // 2
    double x6 = x4 * x2;        // 3
    double x8 = x4 * x4;        // 3
    double x9 = x8 * x;         // 4
    double x15 = x6 * x9;       // 5
    double x16 = x8 * x8;       // 4
    double x28 = x16 * x8 * x4; // 6
    double x32 = x16 * x16;     // 5
    double x64 = x32 * x32;     // 6

    cout << "x^4 = " << x4 << endl;
    cout << "x^6 = " << x6 << endl;
    cout << "x^9 = " << x9 << endl;
    cout << "x^15 = " << x15 << endl;
    cout << "x^28 = " << x28 << endl;
    cout << "x^64 = " << x64 << endl;

    return 0;
}