#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class ThreeByteError : public exception {
public:
    const char* what() const noexcept override {
        return "Помилка трьохбайтного числа";
    }
};

class OverflowError : public ThreeByteError {
public:
    const char* what() const noexcept override {
        return "Переповнення діапазону";
    }
};

class DivisionByZeroError : public ThreeByteError {
public:
    const char* what() const noexcept override {
        return "Ділення на нуль";
    }
};

class ThreeByteInt {
private:
    int value;
    static const int MIN = -(1 << 23);
    static const int MAX = (1 << 23) - 1;

    void check(int x) {
        if (x < MIN || x > MAX)
            throw OverflowError();
    }

public:
    ThreeByteInt(int x = 0) {
        check(x);
        value = x;
    }

    int getValue() const {
        return value;
    }

    friend istream& operator>>(istream& in, ThreeByteInt& x) {
        int temp;
        in >> temp;
        x.check(temp);
        x.value = temp;
        return in;
    }

    friend ostream& operator<<(ostream& out, const ThreeByteInt& x) {
        out << x.value;
        return out;
    }

    ThreeByteInt operator+(const ThreeByteInt& other) const {
        long long res = (long long)value + other.value;
        if (res < MIN || res > MAX) throw OverflowError();
        return ThreeByteInt((int)res);
    }

    ThreeByteInt operator-(const ThreeByteInt& other) const {
        long long res = (long long)value - other.value;
        if (res < MIN || res > MAX) throw OverflowError();
        return ThreeByteInt((int)res);
    }

    ThreeByteInt operator*(const ThreeByteInt& other) const {
        long long res = (long long)value * other.value;
        if (res < MIN || res > MAX) throw OverflowError();
        return ThreeByteInt((int)res);
    }

    ThreeByteInt operator/(const ThreeByteInt& other) const {
        if (other.value == 0)
            throw DivisionByZeroError();

        return ThreeByteInt(value / other.value);
    }
};

ThreeByteInt power(ThreeByteInt x, int n) {
    ThreeByteInt result(1);

    for (int i = 0; i < n; i++) {
        result = result * x;
    }

    return result;
}

int main() {
    try {
        int n;
        cout << "Введіть кількість чисел: ";
        cin >> n;

        vector<ThreeByteInt> arr(n);

        cout << "Введіть числа:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ThreeByteInt sum(0);

        for (int i = 0; i < n; i++) {
            sum = sum + arr[i];
        }

        cout << "Сума чисел = " << sum << endl;

        ThreeByteInt x;
        int degree;

        cout << "\nВведіть x: ";
        cin >> x;

        cout << "Введіть степінь n: ";
        cin >> degree;

        cout << "x^n = " << power(x, degree) << endl;
    }
    catch (const ThreeByteError& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}
