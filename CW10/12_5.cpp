    #include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Помилка: файл input.txt не знайдено!" << endl;
        return 1;
    }

    vector<unsigned long long> numbers;
    unsigned long long value;

    // Зчитуємо всі числа з файлу
    while (fin >> value) {
        numbers.push_back(value);
    }
    fin.close();

    ofstream fout("output.txt");
    if (!fout.is_open()) {
        cerr << "Помилка: неможливо відкрити output.txt для запису!" << endl;
        return 1;
    }

    fout << fixed << setprecision(3);

    // Виводимо квадратні корені у зворотному порядку
    for (int i = numbers.size() - 1; i >= 0; i--) {
        fout << sqrt((long double)numbers[i]) << endl;
    }

    fout.close();
    cout << "Результати успішно записані у файл output.txt" << endl;

    return 0;
}
