#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    int N, M, k;
    double A[MAX][MAX];

    cin >> N >> M >> k;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    double sum = 0;

    // індекси в програмі з 0, тому умова така сама: i - j == k
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i - j == k) {
                sum += A[i][j];
            }
        }
    }

    cout << "Sum = " << sum << endl;

    return 0;
}