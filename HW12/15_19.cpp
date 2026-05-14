#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial {
private:
    vector<double> a;

public:
    Polynomial(int n = 1) {
        a.resize(n, 0);
    }

    void input() {
        cout << "Кількість коефіцієнтів: ";
        int n;
        cin >> n;
        a.resize(n);

        for (int i = 0; i < n; i++) {
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }

    void output() const {
        for (int i = a.size() - 1; i >= 0; i--) {
            cout << a[i] << "x^" << i;
            if (i != 0) cout << " + ";
        }
        cout << endl;
    }

    double value(double x) const {
        double s = 0;
        for (int i = 0; i < a.size(); i++)
            s += a[i] * pow(x, i);
        return s;
    }

    Polynomial derivative() const {
        Polynomial d(a.size() - 1);

        for (int i = 1; i < a.size(); i++)
            d.a[i - 1] = a[i] * i;

        return d;
    }

    Polynomial operator+(const Polynomial& p) const {
        int n = max(a.size(), p.a.size());
        Polynomial r(n);

        for (int i = 0; i < n; i++) {
            double x = i < a.size() ? a[i] : 0;
            double y = i < p.a.size() ? p.a[i] : 0;
            r.a[i] = x + y;
        }

        return r;
    }

    Polynomial operator-(const Polynomial& p) const {
        int n = max(a.size(), p.a.size());
        Polynomial r(n);

        for (int i = 0; i < n; i++) {
            double x = i < a.size() ? a[i] : 0;
            double y = i < p.a.size() ? p.a[i] : 0;
            r.a[i] = x - y;
        }

        return r;
    }

    Polynomial operator*(const Polynomial& p) const {
        Polynomial r(a.size() + p.a.size() - 1);

        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < p.a.size(); j++)
                r.a[i + j] += a[i] * p.a[j];

        return r;
    }
};

int main() {
    Polynomial P1, P2;

    cout << "Введіть P1:\n";
    P1.input();

    cout << "Введіть P2:\n";
    P2.input();

    cout << "\nP1 = ";
    P1.output();

    cout << "P2 = ";
    P2.output();

    Polynomial result = P1 - P2 * (P1 + P2);

    cout << "\nРезультат P1 - P2 * (P1 + P2):\n";
    result.output();

    double x;
    cout << "\nВведіть x: ";
    cin >> x;

    cout << "Значення результату в точці x = " << result.value(x) << endl;

    cout << "Похідна результату:\n";
    result.derivative().output();

    return 0;
}
