#include <iostream>
#include <vector>
using namespace std;

// Функція для виводу матриці
void printMatrix(const vector<vector<int>>& M) {
    int N = M.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

// Функція для повороту матриці на 90 градусів
vector<vector<int>> rotate90(const vector<vector<int>>& M) {
    int N = M.size();
    vector<vector<int>> R(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            R[j][N - 1 - i] = M[i][j];
        }
    }
    return R;
}

int main() {
    int n;
    cout << "Введіть n: ";
    cin >> n;
    int N = 2 * n + 1;

    vector<vector<int>> A(N, vector<int>(N));

    cout << "Введіть матрицю " << N << "x" << N << ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nПочаткова матриця:" << endl;
    printMatrix(A);

    vector<vector<int>> B = rotate90(A);

    cout << "\nМатриця після повороту на 90 градусів:" << endl;
    printMatrix(B);

    return 0;
}
