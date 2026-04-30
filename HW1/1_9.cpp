#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b;

    cin >> a >> b;

    // середнє арифметичне
    double arithmetic = (a + b) / 2;

    // середнє гармонічне
    double harmonic = 2 * a * b / (a + b);

    // десятковий формат
    cout << fixed;
    cout << "Arithmetic = " << arithmetic << endl;
    cout << "Harmonic = " << harmonic << endl;

    // науковий формат
    cout << scientific;
    cout << "Arithmetic = " << arithmetic << endl;
    cout << "Harmonic = " << harmonic << endl;

    return 0;
}