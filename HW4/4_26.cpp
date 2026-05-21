#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int n, m;
    cin >> n >> m;

    int d = gcd(n, m);

    n /= d;
    m /= d;

    if (m < 0) {
        n = -n;
        m = -m;
    }

    cout << n << "/" << m << endl;

    return 0;
}