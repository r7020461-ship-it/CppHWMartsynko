#include <iostream>
using namespace std;

double* inputVector(int n) {
    double* v = new double[n];

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    return v;
}

int main() {
    int n;
    cin >> n;

    double* a = inputVector(n);
    double* b = inputVector(n);

    double scalar = 0;

    for (int i = 0; i < n; i++) {
        scalar += a[i] * b[i];
    }

    cout << "Scalar product = " << scalar << endl;

    delete[] a;
    delete[] b;

    return 0;
}