#include <iostream>
#include <cmath>
using namespace std;

struct Pole {
    char bukva;
    int cifra;
};

bool bishopCanMove(Pole a, Pole b) {
    int x1 = a.bukva - 'a' + 1;
    int y1 = a.cifra;

    int x2 = b.bukva - 'a' + 1;
    int y2 = b.cifra;

    return abs(x1 - x2) == abs(y1 - y2);
}

int main() {
    Pole p1, p2;

    cin >> p1.bukva >> p1.cifra;
    cin >> p2.bukva >> p2.cifra;

    if (bishopCanMove(p1, p2))
        cout << "Ferz mozhe pereity" << endl;
    else
        cout << "Ferz ne mozhe pereity" << endl;

    return 0;
}