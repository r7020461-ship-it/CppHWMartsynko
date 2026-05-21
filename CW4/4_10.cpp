#include <iostream>
#include <limits>
using namespace std;

int main() {
    float a = 1.0f;

    while (1.0f + a != 1.0f) {
        a /= 2.0f;
    }

    cout << "Машинний нуль для float: " << a << endl;
    cout << "Перевірка: 1 + a = " << 1.0f + a << endl;

    cout << "epsilon float = "
         << numeric_limits<float>::epsilon() << endl;

    return 0;
}