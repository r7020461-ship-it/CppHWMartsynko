#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    // знаходимо за модулем
    double max_val = a;
    double min_val = a;

    if (abs(b) > abs(max_val)) max_val = b;
    if (abs(c) > abs(max_val)) max_val = c;

    if (abs(b) < abs(min_val)) min_val = b;
    if (abs(c) < abs(min_val)) min_val = c;

    cout << "Max by abs = " << max_val << endl;
    cout << "Min by abs = " << min_val << endl;

    return 0;
}