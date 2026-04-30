#include <iostream>
using namespace std;

int countEven(int a[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0) k++;
    return k;
}

int countOdd(int a[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0) k++;
    return k;
}

int main() {
    const int MAX = 50;
    int a[MAX], n = 0, x;

    while (n < MAX) {
        cin >> x;
        if (x == 0) break;
        a[n] = x;
        n++;
    }

    cout << "Parnyh = " << countEven(a, n) << endl;
    cout << "Neparnyh = " << countOdd(a, n) << endl;

    return 0;
}