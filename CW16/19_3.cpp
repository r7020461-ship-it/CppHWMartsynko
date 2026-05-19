#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <numeric>
#include <cmath>

using namespace std;

class Rational {
private:
    long long numerator;
    long long denominator;

    void normalize() {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        long long g = gcd(llabs(numerator), llabs(denominator));
        if (g != 0) {
            numerator /= g;
            denominator /= g;
        }
    }

public:
    Rational(long long n = 0, long long d = 1) {
        numerator = n;
        denominator = d;
        normalize();
    }

    Rational operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero");
        }
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const Rational& r) {
        if (r.denominator == 1) {
            out << r.numerator;
        } else {
            out << r.numerator << "/" << r.denominator;
        }
        return out;
    }
};

template <typename T>
class Polynomial {
private:
    list<T> coefficients;

    void removeTrailingZeros() {
        while (!coefficients.empty() && coefficients.back() == T(0)) {
            coefficients.pop_back();
        }
    }

public:
    Polynomial() {}

    Polynomial(const list<T>& coeffs) {
        coefficients = coeffs;
        removeTrailingZeros();
    }

    int degree() const {
        if (coefficients.empty()) {
            return -1;
        }
        return static_cast<int>(coefficients.size()) - 1;
    }

    Polynomial operator+(const Polynomial& other) const {
        list<T> result;

        auto it1 = coefficients.begin();
        auto it2 = other.coefficients.begin();

        while (it1 != coefficients.end() || it2 != other.coefficients.end()) {
            T a = T(0);
            T b = T(0);

            if (it1 != coefficients.end()) {
                a = *it1;
                ++it1;
            }

            if (it2 != other.coefficients.end()) {
                b = *it2;
                ++it2;
            }

            result.push_back(a + b);
        }

        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        if (coefficients.empty() || other.coefficients.empty()) {
            return Polynomial();
        }

        vector<T> a(coefficients.begin(), coefficients.end());
        vector<T> b(other.coefficients.begin(), other.coefficients.end());
        vector<T> result(a.size() + b.size() - 1, T(0));

        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; j < b.size(); j++) {
                result[i + j] = result[i + j] + a[i] * b[j];
            }
        }

        return Polynomial(list<T>(result.begin(), result.end()));
    }

    T value(T x) const {
        T result = T(0);

        for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it) {
            result = result * x + *it;
        }

        return result;
    }

    void print() const {
        if (coefficients.empty()) {
            cout << 0;
            return;
        }

        int power = 0;
        bool first = true;

        for (const T& coef : coefficients) {
            if (coef != T(0)) {
                if (!first) {
                    cout << " + ";
                }
                cout << "(" << coef << ")";
                if (power > 0) {
                    cout << "x";
                    if (power > 1) {
                        cout << "^" << power;
                    }
                }
                first = false;
            }
            power++;
        }

        if (first) {
            cout << 0;
        }
    }
};

int main() {
    Polynomial<int> p1({1, 2, 3});
    Polynomial<int> p2({4, 0, 1});

    cout << "Polinom p1: ";
    p1.print();
    cout << endl;

    cout << "Polinom p2: ";
    p2.print();
    cout << endl;

    cout << "Degree p1 = " << p1.degree() << endl;

    cout << "p1 + p2 = ";
    (p1 + p2).print();
    cout << endl;

    cout << "p1 * p2 = ";
    (p1 * p2).print();
    cout << endl;

    cout << "p1(2) = " << p1.value(2) << endl;

    cout << endl;

    Polynomial<double> q1({1.5, 2.0, -0.5});
    Polynomial<double> q2({2.0, 1.0});

    cout << "Polinom q1: ";
    q1.print();
    cout << endl;

    cout << "q1 + q2 = ";
    (q1 + q2).print();
    cout << endl;

    cout << "q1 * q2 = ";
    (q1 * q2).print();
    cout << endl;

    cout << "q1(2.5) = " << q1.value(2.5) << endl;

    cout << endl;

    Polynomial<Rational> r1({Rational(1, 2), Rational(2, 3), Rational(1, 4)});
    Polynomial<Rational> r2({Rational(3, 4), Rational(1, 3)});

    cout << "Polinom r1: ";
    r1.print();
    cout << endl;

    cout << "Polinom r2: ";
    r2.print();
    cout << endl;

    cout << "Degree r1 = " << r1.degree() << endl;

    cout << "r1 + r2 = ";
    (r1 + r2).print();
    cout << endl;

    cout << "r1 * r2 = ";
    (r1 * r2).print();
    cout << endl;

    cout << "r1(2/1) = " << r1.value(Rational(2, 1)) << endl;

    return 0;
}