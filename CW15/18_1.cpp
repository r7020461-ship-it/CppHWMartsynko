#include <iostream>
#include <string>
using namespace std;

namespace MyTask {

template <class T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

class Rational {
private:
    int num, den;

public:
    Rational(int n = 0, int d = 1) {
        num = n;
        den = (d == 0) ? 1 : d;
    }

    bool operator>(const Rational& other) const {
        return num * other.den > other.num * den;
    }

    friend ostream& operator<<(ostream& out, const Rational& r) {
        out << r.num << "/" << r.den;
        return out;
    }
};

}

int main() {
    using namespace MyTask;

    cout << "max int: " << maximum(5, 9) << endl;
    cout << "max double: " << maximum(3.14, 2.71) << endl;
    cout << "max char: " << maximum('a', 'z') << endl;

    string s1 = "apple", s2 = "banana";
    cout << "max string: " << maximum(s1, s2) << endl;

    Rational r1(3, 4), r2(5, 6);
    cout << "max rational: " << maximum(r1, r2) << endl;

    return 0;
}
