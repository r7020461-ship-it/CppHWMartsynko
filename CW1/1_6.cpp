#include <iostream>
using namespace std;

int main() {
    double C, F;

    cout << "Введіть температуру в градусах Цельсія C: ";
    cin >> C;

    F = 9.0 / 5.0 * C + 32;

    cout << "F=" << F << endl;

    return 0;
}