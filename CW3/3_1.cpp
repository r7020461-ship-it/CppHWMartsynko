#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int hundreds = n / 100;
    int tens = (n / 10) % 10;
    int ones = n % 10;

    int sum = hundreds + tens + ones;
    int reversed = ones * 100 + tens * 10 + hundreds;

    cout << "Hundreds = " << hundreds << endl;
    cout << "Tens = " << tens << endl;
    cout << "Ones = " << ones << endl;
    cout << "Sum = " << sum << endl;
    cout << "Reversed = " << reversed << endl;

    return 0;
}
