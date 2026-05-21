#include <iostream>
using namespace std;

void printInt128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    string s;
    while (x > 0) {
        s = char('0' + x % 10) + s;
        x /= 10;
    }
    cout << s;
}

int main() {
    int n;
    cin >> n;

    __int128 d0 = 1; // !0
    __int128 d1 = 0; // !1

    if (n == 0) {
        printInt128(d0);
    } else if (n == 1) {
        printInt128(d1);
    } else {
        __int128 d;
        for (int i = 2; i <= n; i++) {
            d = (i - 1) * (d1 + d0);
            d0 = d1;
            d1 = d;
        }
        printInt128(d1);
    }

    return 0;
}