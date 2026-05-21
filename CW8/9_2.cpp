#include <iostream>
#include <cmath>
using namespace std;

int inputArray(int a[]) {
    int x, n = 0;

    while (cin >> x && x != 0 && n < 100) {
        a[n] = x;
        n++;
    }

    return n;
}

bool isSquare(int x) {
    if (x < 0) return false;
    int r = sqrt(x);
    return r * r == x;
}

bool isCube(int x) {
    int r = round(cbrt(x));
    return r * r * r == x;
}

int main() {
    int a[100];

    int n = inputArray(a);

    int squares = 0, cubes = 0;

    for (int i = 0; i < n; i++) {
        if (isSquare(a[i])) squares++;
        if (isCube(a[i])) cubes++;
    }

    cout << "Kvadrativ = " << squares << endl;
    cout << "Kubiv = " << cubes << endl;

    return 0;
}