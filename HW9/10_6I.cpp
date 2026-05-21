#include <iostream>
using namespace std;

struct Vector {
    int n;        // розмір
    double* data; // масив значень
};

void inputVector(Vector& v) {
    cout << "Vvedit rozmir vektora: ";
    cin >> v.n;

    v.data = new double[v.n];

    cout << "Vvedit elementy:" << endl;
    for (int i = 0; i < v.n; i++) {
        cin >> v.data[i];
    }
}

void printVector(const Vector& v) {
    cout << "Vector: ";
    for (int i = 0; i < v.n; i++) {
        cout << v.data[i] << " ";
    }
    cout << endl;
}

void deleteVector(Vector& v) {
    delete[] v.data;
    v.data = nullptr;
    v.n = 0;
}

int main() {
    Vector v;

    inputVector(v);
    printVector(v);

    deleteVector(v);

    return 0;
}
