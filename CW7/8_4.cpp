#include <iostream>
using namespace std;

void inputMatrix(double a[25][25], int m, int n) {
    for (int i = 0; i < m; i++) {
        cout << "Vvedit " << i + 1 << " ryadok: ";
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void printMatrix(double a[25][25], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    double a[25][25];

    cin >> m >> n;

    if (m <= 0 || m >= 25 || n <= 0 || n >= 25) {
        cout << "Pomylka";
        return 0;
    }

    inputMatrix(a, m, n);
    printMatrix(a, m, n);

    return 0;
}