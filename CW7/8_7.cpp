#include <iostream>
using namespace std;

double det(double a[100][100], int n) {
    double d = 1;

    for (int i = 0; i < n; i++) {
        int p = i;
        for (int j = i + 1; j < n; j++)
            if (abs(a[j][i]) > abs(a[p][i])) p = j;

        if (a[p][i] == 0) return 0;

        if (p != i) {
            for (int j = 0; j < n; j++)
                swap(a[i][j], a[p][j]);
            d = -d;
        }

        d *= a[i][i];

        for (int j = i + 1; j < n; j++) {
            double k = a[j][i] / a[i][i];
            for (int t = i; t < n; t++)
                a[j][t] -= k * a[i][t];
        }
    }

    return d;
}

int main() {
    int n;
    double a[100][100];

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Determinant = " << det(a, n) << endl;

    return 0;
}