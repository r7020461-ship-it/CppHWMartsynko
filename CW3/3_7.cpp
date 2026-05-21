#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    // a) ax^2 + bx + c = 0
    double D = b * b - 4 * a * c;

    cout << "a) ";

    if (D > 0) {
        double x1 = (-b - sqrt(D)) / (2 * a);
        double x2 = (-b + sqrt(D)) / (2 * a);
        cout << "2 rozviazky: " << x1 << " " << x2 << endl;
    } else if (D == 0) {
        double x = -b / (2 * a);
        cout << "1 rozviazok: " << x << endl;
    } else {
        cout << "0 rozviazkiv" << endl;
    }

    // b) ax^4 + bx^2 + c = 0
    cout << "b) ";

    D = b * b - 4 * a * c;

    if (D < 0) {
        cout << "0 rozviazkiv" << endl;
    } else {
        double y1 = (-b - sqrt(D)) / (2 * a);
        double y2 = (-b + sqrt(D)) / (2 * a);

        int count = 0;

        if (y1 > 0) count += 2;
        else if (y1 == 0) count += 1;

        if (y2 > 0 && y2 != y1) count += 2;
        else if (y2 == 0 && y2 != y1) count += 1;

        cout << count << " rozviazkiv: ";

        if (y1 > 0) cout << -sqrt(y1) << " " << sqrt(y1) << " ";
        else if (y1 == 0) cout << 0 << " ";

        if (y2 > 0 && y2 != y1) cout << -sqrt(y2) << " " << sqrt(y2) << " ";
        else if (y2 == 0 && y2 != y1) cout << 0;

        cout << endl;
    }

    return 0;
}