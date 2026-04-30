#include <iostream>
using namespace std;

long long doubleFactorial(int n) {
    long long result = 1;

    for (int i = n; i >= 1; i -= 2) {
        result *= i;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    cout << n << "!! = " << doubleFactorial(n) << endl;

    return 0;
}