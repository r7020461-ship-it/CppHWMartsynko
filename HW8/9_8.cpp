#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> all;
    int n;

    while (true) {
        cout << "Введіть розмір вектора: ";
        cin >> n;

        if (n <= 0) break;

        cout << "Введіть елементи: ";
        for (int i = 0; i < n; i++) {
            double x;
            cin >> x;
            all.push_back(x);
        }

        double sum = 0;
        for (double x : all)
            sum += x;

        double average = sum / all.size();

        double variance = 0;
        for (double x : all)
            variance += (x - average) * (x - average);

        variance /= all.size();

        cout << "Середнє арифметичне = " << average << endl;
        cout << "Дисперсія = " << variance << endl;
    }

    return 0;
}
