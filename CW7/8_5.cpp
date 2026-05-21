#include <iostream>
using namespace std;

const int N = 3; // розмір матриці (можна змінити)

// Функція для транспонування матриці
void transpose(int a[N][N], int b[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[j][i] = a[i][j];
        }
    }
}

// Функція для виводу матриці
void printMatrix(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][N]; // транспонована матриця

    cout << "Початкова матриця:" << endl;
    printMatrix(A);

    transpose(A, B);

    cout << "\nТранспонована матриця:" << endl;
    printMatrix(B);

    return 0;
}
