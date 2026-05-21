#include <iostream>
using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int maxArray(int a[], int n) {
    int max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

int main() {
    const int N = 5;
    int a[N];

    inputArray(a, N);

    cout << "Max = " << maxArray(a, N) << endl;

    return 0;
}