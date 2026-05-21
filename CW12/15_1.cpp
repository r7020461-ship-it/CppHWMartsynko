#include <iostream>
#include <cmath>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void reduce() {
        int d = gcd(numerator, denominator);
        numerator /= d;
        denominator /= d;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Rational() {
        numerator = 1;
        denominator = 1;
    }

    Rational(int n, int d) {
        numerator = n;
        if (d == 0) {
            cout << "Помилка: знаменник не може бути нулем. Встановлено 1." << endl;
            denominator = 1;
        } else {
            denominator = d;
        }
        reduce();
    }

    void input() {
        cout << "Введіть чисельник: ";
        cin >> numerator;

        do {
            cout << "Введіть знаменник: ";
            cin >> denominator;

            if (denominator == 0)
                cout << "Знаменник не може бути нулем!" << endl;

        } while (denominator == 0);

        reduce();
    }

    void output() const {
        cout << numerator << "/" << denominator;
    }

    Rational operator+(const Rational& other) {
        return Rational(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Rational operator*(const Rational& other) {
        return Rational(
            numerator * other.numerator,
            denominator * other.denominator
        );
    }

    bool operator<(const Rational& other) {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Rational& other) {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool operator==(const Rational& other) {
        return numerator == other.numerator &&
               denominator == other.denominator;
    }
};

int main() {
    Rational a, b;

    cout << "Введіть перше раціональне число:" << endl;
    a.input();

    cout << "Введіть друге раціональне число:" << endl;
    b.input();

    cout << "\na = ";
    a.output();

    cout << "\nb = ";
    b.output();

    Rational sum = a + b;
    Rational product = a * b;

    cout << "\na + b = ";
    sum.output();

    cout << "\na * b = ";
    product.output();

    cout << endl;

    if (a > b)
        cout << "a більше за b" << endl;
    else if (a < b)
        cout << "a менше за b" << endl;
    else
        cout << "a дорівнює b" << endl;

    return 0;
}
