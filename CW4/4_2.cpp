#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n << "! = ";

    for (int i = 1; i <= n; i++) {
        cout << i;
        if (i != n) cout << "*";
    }

    cout << endl;

    cout << n << "! = ";

    for (int i = n; i >= 1; i--) {
        cout << i;
        if (i != 1) cout << "*";
    }

    return 0;
}