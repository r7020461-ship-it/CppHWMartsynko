#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mn = a[0] + a[1];

    for (int i = 1; i < n - 1; i++) {
        int sum = a[i] + a[i + 1];
        if (sum < mn) {
            mn = sum;
        }
    }

    cout << "Min = " << mn << endl;

    return 0;
}