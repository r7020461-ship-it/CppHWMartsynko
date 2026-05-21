#include <iostream>
#include <cmath>
using namespace std;

// Функція для обчислення многочлена з пункту (a)
int polynomialA(int n, int x) {
    int result = 0;
    for (int i = n; i >= 0; i--) {
        result += pow(x, i);
    }
    return result;
}

// Функція для обчислення многочлена з пункту (б)
int polynomialB(int n, int x, int y) {
    int result = 0;
    for (int i = n; i >= 1; i--) {
        result += pow(x, 2 * i) * pow(y, i);
    }
    result += 1; // додаємо останній член "+1"
    return result;
}

int main() {
    // (a) y = x^n + x^(n-1) + ... + x^2 + x + 1, n=3, x=2
    int n1 = 3, x1 = 2;
    int resultA = polynomialA(n1, x1);
    cout << "Результат (a): " << resultA << endl;

    // (б) y = x^(2n)y^n + x^(2n-1)y^(n-1) + ... + x^2y + 1, n=4, x=1, y=2
    int n2 = 4, x2 = 1, y2 = 2;
    int resultB = polynomialB(n2, x2, y2);
    cout << "Результат (б): " << resultB << endl;

    return 0;
}
