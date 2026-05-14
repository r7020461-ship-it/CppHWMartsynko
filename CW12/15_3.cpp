#include <iostream>
#include <fstream>
using namespace std;

class Polynomial {
private:
    int n;
    double* a;

public:
    Polynomial(int size = 1) {
        n = size;
        a = new double[n]{};
    }

    Polynomial(const Polynomial& other) {
        n = other.n;
        a = new double[n];
        for (int i = 0; i < n; i++)
            a[i] = other.a[i];
    }

    ~Polynomial() {
        delete[] a;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] a;
            n = other.n;
            a = new double[n];
            for (int i = 0; i < n; i++)
                a[i] = other.a[i];
        }
        return *this;
    }

    void input() {
        for (int i = 0; i < n; i++) {
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }

    void output() const {
        for (int i = 0; i < n; i++) {
            cout << a[i] << "x^" << i;
            if (i != n - 1) cout << " + ";
        }
        cout << endl;
    }

    double operator[](int index) const {
        return a[index];
    }

    friend ostream& operator<<(ostream& out, const Polynomial& p);
    friend istream& operator>>(istream& in, Polynomial& p);
    friend void writeBinary(const char* filename, const Polynomial& p);
    friend void readBinary(const char* filename, Polynomial& p);
};

ostream& operator<<(ostream& out, const Polynomial& p) {
    for (int i = 0; i < p.n; i++) {
        out << p.a[i] << "x^" << i;
        if (i != p.n - 1) out << " + ";
    }
    return out;
}

istream& operator>>(istream& in, Polynomial& p) {
    for (int i = 0; i < p.n; i++)
        in >> p.a[i];
    return in;
}

void writeBinary(const char* filename, const Polynomial& p) {
    ofstream fout(filename, ios::binary);
    fout.write((char*)&p.n, sizeof(p.n));
    fout.write((char*)p.a, p.n * sizeof(double));
    fout.close();
}

void readBinary(const char* filename, Polynomial& p) {
    ifstream fin(filename, ios::binary);

    delete[] p.a;

    fin.read((char*)&p.n, sizeof(p.n));
    p.a = new double[p.n];
    fin.read((char*)p.a, p.n * sizeof(double));

    fin.close();
}

int main() {
    int n;
    cout << "Введіть кількість коефіцієнтів полінома: ";
    cin >> n;

    Polynomial p(n);

    cout << "Введіть коефіцієнти полінома:\n";
    cin >> p;

    cout << "Поліном:\n";
    cout << p << endl;

    writeBinary("polynomial.bin", p);

    Polynomial q;
    readBinary("polynomial.bin", q);

    cout << "Поліном з бінарного файлу:\n";
    cout << q << endl;

    return 0;
}