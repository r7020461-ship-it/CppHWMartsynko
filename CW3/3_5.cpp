#include <iostream>
using namespace std;

int main() {
    double a, b;

    cin >> a >> b;

    if (a > b) {
        cout << "Більше: " << a << endl;
        cout << "Менше: " << b << endl;
    } else if (b > a) {
        cout << "Більше: " << b << endl;
        cout << "Менше: " << a << endl;
    } else {
        cout << "Числа рівні" << endl;
    }

    return 0;
}