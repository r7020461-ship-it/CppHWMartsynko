#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;

    int k = 0;
    int p = 1; // 4^0

    while (p * 4 <= m) {
        p *= 4;
        k++;
    }

    cout << "k = " << k << endl;

    return 0;
}