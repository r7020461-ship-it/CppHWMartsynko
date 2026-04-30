#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, y;

    cin >> a;
    cin >> y;

    double result = pow(a, y);

    // десяткове представлення
    cout << "Decimal: " << fixed << result << endl;

    // наукове представлення
    cout << "Scientific: " << scientific << result << endl;

    return 0;
}
