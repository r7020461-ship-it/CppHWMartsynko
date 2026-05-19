#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int maxInRow(const list<int>& row) {
    int maxElement = *row.begin();

    for (int x : row) {
        if (x > maxElement) {
            maxElement = x;
        }
    }

    return maxElement;
}

void inputMatrix(vector<list<int>>& matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        list<int> row;

        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }

        matrix.push_back(row);
    }
}

void printMatrix(const vector<list<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;

    cout << "Vvedit n ta m: ";
    cin >> n >> m;

    if (n <= 0 || m <= 0 || n >= 100 || m >= 100) {
        cout << "n ta m maiut buty naturalnymy chyslamy menshymy za 100" << endl;
        return 0;
    }

    vector<list<int>> matrix;

    cout << "Vvedit elementy matrytsi:" << endl;
    inputMatrix(matrix, n, m);

    stable_sort(matrix.begin(), matrix.end(),
        [](const list<int>& a, const list<int>& b) {
            return maxInRow(a) > maxInRow(b);
        }
    );

    cout << "Matrytsia pislia perestanovky riadkiv:" << endl;
    printMatrix(matrix);

    return 0;
}