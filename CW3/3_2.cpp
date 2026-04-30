#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = n / 100;        // сотні
    int b = (n / 10) % 10;  // десятки
    int c = n % 10;         // одиниці

    // перевірка, що всі цифри різні
    if (a != b && a != c && b != c) {
        cout << a << b << c << endl;
        cout << a << c << b << endl;
        cout << b << a << c << endl;
        cout << b << c << a << endl;
        cout << c << a << b << endl;
        cout << c << b << a << endl;
    } else {
        cout << "Цифри не різні" << endl;
    }

    return 0;
}