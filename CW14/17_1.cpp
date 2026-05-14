#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>
using namespace std;

class Rational {
private:
    int num, den;

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
        if (den == 0)
            throw invalid_argument("Знаменник не може бути нулем!");

        int d = gcd(num, den);
        num /= d;
        den /= d;

        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Rational(int n = 0, int d = 1) {
        num = n;
        den = d;
        reduce();
    }

    friend istream& operator>>(istream& in, Rational& r) {
        cout << "Чисельник: ";
        in >> r.num;
        cout << "Знаменник: ";
        in >> r.den;

        r.reduce();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Rational& r) {
        out << r.num << "/" << r.den;
        return out;
    }

    Rational operator-(const Rational& other) const {
        return Rational(num * other.den - other.num * den,
                        den * other.den);
    }

    Rational operator*(const Rational& other) const {
        return Rational(num * other.num, den * other.den);
    }

    Rational operator/(const Rational& other) const {
        if (other.num == 0)
            throw invalid_argument("Ділення на нуль неможливе!");

        return Rational(num * other.den, den * other.num);
    }

    friend void writeToFile(const Rational& r, const string& filename);
};

void writeToFile(const Rational& r, const string& filename) {
    ofstream fout(filename);

    if (!fout.is_open())
        throw runtime_error("Не вдалося відкрити файл!");

    fout << r;
    fout.close();
}

int main() {
    try {
        Rational a, b;

        cout << "Введіть перший дріб:\n";
        cin >> a;

        cout << "Введіть другий дріб:\n";
        cin >> b;

        cout << "\na = " << a << endl;
        cout << "b = " << b << endl;

        cout << "a - b = " << a - b << endl;
        cout << "a * b = " << a * b << endl;
        cout << "a / b = " << a / b << endl;

        writeToFile(a, "rational.txt");
        cout << "\nДріб записано у файл rational.txt" << endl;
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}
