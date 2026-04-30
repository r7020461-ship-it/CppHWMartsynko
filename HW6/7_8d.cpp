#include <iostream>
#include <cmath>
using namespace std;

bool isCube(int x) {
    int r = round(cbrt(x));
    return r * r * r == x;
}

int main() {
    int N;
    cin >> N;

    int a[100];
    int count = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];

        if (a[i] % 3 == 0 && isCube(a[i])) {
            count++;
        }
    }

    cout << "Kilkist = " << count << endl;

    return 0;
}
