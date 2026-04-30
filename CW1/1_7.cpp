#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;
    cout << "Введіть число x: ";
    cin >> x;

    // Без математичних функцій
    int integer_part = (int)x;              // ціла частина
    double fractional_part = x - integer_part; // дробова частина

    // З математичними функціями
    double floor_val = floor(x); // найбільше ціле ≤ x
    double ceil_val = ceil(x);   // найменше ціле ≥ x
    double round_val = round(x); // округлення

    cout << "Ціла частина: " << integer_part << endl;
    cout << "Дробова частина: " << fractional_part << endl;
    cout << "floor(x): " << floor_val << endl;
    cout << "ceil(x): " << ceil_val << endl;
    cout << "round(x): " << round_val << endl;

    return 0;
}