#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int p = 1; // 2^0

    while (p <= n) {
        p *= 2;
    }

    cout << p << endl;

    return 0;
}