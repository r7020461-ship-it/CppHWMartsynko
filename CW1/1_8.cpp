#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b;

    cin >> a;
    cin >> b;

    double riznytsia = a - b;
    double dobutok = a * b;

    cout << fixed;
    cout << "Різниця = " << riznytsia << endl;
    cout << "Добуток = " << dobutok << endl;

    return 0;
}