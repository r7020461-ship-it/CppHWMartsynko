#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double gamma = 6.673e-11;
    double m1 = 5.97e24;
    double m2 = 7.35e22;
    double r = 3.84e8;

    double F = gamma * m1 * m2 / (r * r);

    cout << scientific;
    cout << "F=" << F << endl;

    return 0;
}