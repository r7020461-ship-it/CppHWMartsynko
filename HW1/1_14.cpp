#include <iostream>
using namespace std;

int main() {
    double a, t;

    cout << "Введіть прискорення a: ";
    cin >> a;

    cout << "Введіть час t: ";
    cin >> t;

    double S = a * t * t / 2;
    double v = a * t;

    cout << "S=" << S << endl;
    cout << "v=" << v << endl;

    return 0;
}
