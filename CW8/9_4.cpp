#include <iostream>
using namespace std;

double** createMatrix(int n) {
    double** a = new double*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    }
    return a;
}

void inputMatrix(double** a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}

double** multiply(double** A, double** B, int n) {
    double** C = createMatrix(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];

    return C;
}

void printMatrix(double** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void deleteMatrix(double** a, int n) {
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

int main() {
    int n;
    cin >> n;

    double** A = createMatrix(n);
    double** B = createMatrix(n);

    inputMatrix(A, n);
    inputMatrix(B, n);

    double** C = multiply(A, B, n);

    printMatrix(C, n);

    deleteMatrix(A, n);
    deleteMatrix(B, n);
    deleteMatrix(C, n);

    return 0;
}