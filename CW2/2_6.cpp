#include <iostream>
#include <cmath>
using namespace std;

double length(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double xA, yA, xB, yB, xC, yC;

    cin >> xA >> yA;
    cin >> xB >> yB;
    cin >> xC >> yC;

    double AB = length(xA, yA, xB, yB);
    double BC = length(xB, yB, xC, yC);
    double AC = length(xA, yA, xC, yC);

    double S = area(AB, BC, AC);

    cout << "AB = " << AB << endl;
    cout << "BC = " << BC << endl;
    cout << "AC = " << AC << endl;
    cout << "S = " << S << endl;

    return 0;
}