#include <iostream>
#include <cmath>
using namespace std;

// функція для обчислення суми елементів > e
double sumGreaterThanE(double a[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > M_E) { // число Ейлера
            sum += a[i];
        }
    }
    return sum;
}

int main() {
    const int N = 10;
    double a[N];

    // введення масиву
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    double result = sumGreaterThanE(a, N);

    cout << "Sum = " << result << endl;

    return 0;
}