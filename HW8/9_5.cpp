#include <iostream>
#include <cmath>
using namespace std;

int** inputMatrix(int& n, int& m) {
    cin >> n >> m;

    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    return a;
}

void deleteMatrix(int** a, int n) {
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

int rankMatrix(int** a, int n, int m) {
    double b[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = a[i][j];

    int rank = 0;

    for (int col = 0; col < m && rank < n; col++) {
        int row = rank;

        while (row < n && b[row][col] == 0)
            row++;

        if (row == n) continue;

        for (int j = 0; j < m; j++)
            swap(b[rank][j], b[row][j]);

        double div = b[rank][col];

        for (int j = col; j < m; j++)
            b[rank][j] /= div;

        for (int i = 0; i < n; i++) {
            if (i != rank) {
                double factor = b[i][col];
                for (int j = col; j < m; j++)
                    b[i][j] -= factor * b[rank][j];
            }
        }

        rank++;
    }

    return rank;
}

double determinant(int** a, int n) {
    double b[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = a[i][j];

    double det = 1;

    for (int i = 0; i < n; i++) {
        int p = i;

        for (int j = i + 1; j < n; j++)
            if (abs(b[j][i]) > abs(b[p][i]))
                p = j;

        if (b[p][i] == 0)
            return 0;

        if (p != i) {
            for (int j = 0; j < n; j++)
                swap(b[i][j], b[p][j]);
            det = -det;
        }

        det *= b[i][i];

        for (int j = i + 1; j < n; j++) {
            double k = b[j][i] / b[i][i];

            for (int t = i; t < n; t++)
                b[j][t] -= k * b[i][t];
        }
    }

    return det;
}

int main() {
    int n, m;

    int** a = inputMatrix(n, m);

    cout << "Rank = " << rankMatrix(a, n, m) << endl;

    if (n == m)
        cout << "Determinant = " << determinant(a, n) << endl;
    else
        cout << "Determinant ne isnue, bo matrytsia ne kvadratna" << endl;

    deleteMatrix(a, n);

    return 0;
}