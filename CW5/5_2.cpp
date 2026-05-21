#include <iostream>
using namespace std;

long long fib(int n) {
    long long f0 = 0, f1 = 1;

    if (n == 0) return f0;
    if (n == 1) return f1;

    for (int i = 2; i <= n; i++) {
        long long f = f0 + f1;
        f0 = f1;
        f1 = f;
    }

    return f1;
}

int main() {
    int n;
    long long a;

    cin >> n >> a;

    // a) F_n
    cout << "F_n = " << fib(n) << endl;

    // b) номер найбільшого числа Фібоначчі, яке не перевищує a
    long long f0 = 0, f1 = 1;
    int k = 1;

    while (f1 <= a) {
        long long f = f0 + f1;
        f0 = f1;
        f1 = f;
        k++;
    }

    cout << "b) k = " << k - 1 << endl;

    // c) номер найменшого числа Фібоначчі, яке більше a
    cout << "c) k = " << k << endl;

    // d) сума всіх чисел Фібоначчі, які не перевищують 1000
    long long sum = 0;
    f0 = 0;
    f1 = 1;

    while (f0 <= 1000) {
        sum += f0;
        long long f = f0 + f1;
        f0 = f1;
        f1 = f;
    }

    cout << "d) suma = " << sum << endl;

    return 0;
}