#include <iostream>
#include <string>
using namespace std;

struct Date {
    int day, month, year;
};

struct ChessField {
    char letter;
    int number;
};

struct Point {
    double x, y;
};

struct Rectangle {
    Point A, B;
};

struct Polynomial {
    int degree;
    double* coef;
};

void inputDate(Date& d) {
    cin >> d.day >> d.month >> d.year;
}

void printDate(Date d) {
    cout << d.day << "." << d.month << "." << d.year << endl;
}

void inputChessField(ChessField& f) {
    cin >> f.letter >> f.number;
}

void printChessField(ChessField f) {
    cout << f.letter << f.number << endl;
}

void inputPoint(Point& p) {
    cin >> p.x >> p.y;
}

void inputRectangle(Rectangle& r) {
    inputPoint(r.A);
    inputPoint(r.B);
}

void printRectangle(Rectangle r) {
    cout << "(" << r.A.x << ", " << r.A.y << ") ";
    cout << "(" << r.B.x << ", " << r.B.y << ")" << endl;
}

void inputPolynomial(Polynomial& p) {
    cin >> p.degree;
    p.coef = new double[p.degree + 1];

    for (int i = 0; i <= p.degree; i++) {
        cin >> p.coef[i];
    }
}

void printPolynomial(Polynomial p) {
    for (int i = p.degree; i >= 0; i--) {
        cout << p.coef[i] << "*x^" << i;
        if (i != 0) cout << " + ";
    }
    cout << endl;
}

void deletePolynomial(Polynomial& p) {
    delete[] p.coef;
    p.coef = nullptr;
}

int main() {
    Date d;
    ChessField f;
    Rectangle r;
    Polynomial p;

    inputDate(d);
    inputChessField(f);
    inputRectangle(r);
    inputPolynomial(p);

    printDate(d);
    printChessField(f);
    printRectangle(r);
    printPolynomial(p);

    deletePolynomial(p);

    return 0;
}
