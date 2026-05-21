#include <iostream>
using namespace std;

void inputVector(double v[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

void printVector(double v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sumVectors(double a[], double b[], double c[], int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

double scalarProduct(double a[], double b[], int n) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] * b[i];
    }
    return s;
}

int main() {
    const int MAX = 20;
    int n;
    double a[MAX], b[MAX], c[MAX];

    cin >> n;

    inputVector(a, n);
    inputVector(b, n);

    sumVectors(a, b, c, n);

    cout << "Vector A: ";
    printVector(a, n);

    cout << "Vector B: ";
    printVector(b, n);

    cout << "Sum: ";
    printVector(c, n);

    cout << "Scalar product = " << scalarProduct(a, b, n) << endl;

    return 0;
}