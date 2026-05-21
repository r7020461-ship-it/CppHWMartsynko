#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct {
    int numerator;
    unsigned int denominator;
} Rational;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

Rational reduce(Rational r) {
    int d = gcd(r.numerator, r.denominator);
    r.numerator /= d;
    r.denominator /= d;
    return r;
}

Rational sum(Rational a, Rational b) {
    Rational r;
    r.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    r.denominator = a.denominator * b.denominator;
    return reduce(r);
}

Rational product(Rational a, Rational b) {
    Rational r;
    r.numerator = a.numerator * b.numerator;
    r.denominator = a.denominator * b.denominator;
    return reduce(r);
}

int compare(Rational a, Rational b) {
    int left = a.numerator * b.denominator;
    int right = b.numerator * a.denominator;

    if (left > right) return 1;
    if (left < right) return -1;
    return 0;
}

void print(Rational r) {
    cout << r.numerator << "/" << r.denominator << endl;
}

int main() {
    Rational a, b;

    cin >> a.numerator >> a.denominator;
    cin >> b.numerator >> b.denominator;

    cout << "Suma = ";
    print(sum(a, b));

    cout << "Dobutok = ";
    print(product(a, b));

    int c = compare(a, b);
    if (c == 1) cout << "Pershe bilshe" << endl;
    else if (c == -1) cout << "Druhe bilshe" << endl;
    else cout << "Rivni" << endl;

    cout << "Pershe skorochene = ";
    print(reduce(a));

    cout << "Druhe skorochene = ";
    print(reduce(b));

    return 0;
}