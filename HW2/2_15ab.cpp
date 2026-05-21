#include <iostream>
using namespace std;

double f1(double x, double y) {
    return x*x*x + 3*x*x*y + 3*x*y*y + y*y*y;
}

double f2(double x, double y) {
    return x*x*y*y + x*x*x*y*y*y + x*x*x*x*y*y*y*y;
}

int main() {
    double x, y;
    cin >> x >> y;

    cout << "a) f(x,y) = " << f1(x, y) << endl;
    cout << "b) f(x,y) = " << f2(x, y) << endl;

    return 0;
}
