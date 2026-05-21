#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<unsigned long long> a(n);

    for (int i = 0; i < n; i++) {
        unsigned long long num = 0;
        for (int j = 0; j < 10; j++) {
            int digit;
            cin >> digit;
            num = num * 10 + digit;
        }
        a[i] = num;
    }

    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    cout << "Sum = " << sum << endl;

    return 0;
}