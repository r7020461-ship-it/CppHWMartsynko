#include <iostream>
using namespace std;

int main() {
    double m[3][3] = {
        {1.0, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int i, j;
    double a;

    cin >> i >> j >> a;

    // індекси вводяться від 1 до 3
    if (i >= 1 && i <= 3 && j >= 1 && j <= 3) {
        m[i - 1][j - 1] = a;
    } else {
        cout << "Pomylka: nepravylni indeksy" << endl;
        return 0;
    }

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            cout << m[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}