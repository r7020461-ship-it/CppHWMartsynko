#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    double a[100];
    double sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i] * a[i];
    }

    cout << "Sum = " << sum << endl;

    return 0;
}
