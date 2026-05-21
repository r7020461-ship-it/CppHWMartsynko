#include <iostream>
using namespace std;

// Функція для підрахунку кількості кроків до 1
int collatzSteps(long long n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    int maxSteps = 0;
    int numberWithMaxSteps = 1;

    for (int n = 1; n < 1000; n++) {
        int steps = collatzSteps(n);
        if (steps > maxSteps) {
            maxSteps = steps;
            numberWithMaxSteps = n;
        }
    }

    cout << "Число з максимальною кількістю кроків: " 
         << numberWithMaxSteps << endl;
    cout << "Кількість кроків: " << maxSteps << endl;

    return 0;
}
