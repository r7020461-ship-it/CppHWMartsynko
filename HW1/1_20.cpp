#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    double a, b, c;

    // парсинг рядка
    sscanf(s.c_str(), "A=%lf, B=%lf, C=%lf", &a, &b, &c);

    // середнє арифметичне
    double arithmetic = (a + b + c) / 3;

    // середнє гармонічне
    double harmonic = 3.0 / (1.0/a + 1.0/b + 1.0/c);

    // десятковий формат (фіксована крапка)
    cout << fixed << setprecision(6);
    cout << "Arithmetic = " << arithmetic << endl;
    cout << "Harmonic = " << harmonic << endl;

    // науковий формат
    cout << scientific;
    cout << "Arithmetic = " << arithmetic << endl;
    cout << "Harmonic = " << harmonic << endl;

    return 0;
}