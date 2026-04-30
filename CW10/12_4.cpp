#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Введіть n: ";
    cin >> n;

    vector<int> m(n);
    cout << "Введіть " << n << " цілих чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    // Відкриваємо файл для читання
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Помилка: файл input.txt не знайдено!" << endl;
        return 1;
    }

    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        if (!(fin >> x[i])) {
            cerr << "Помилка: некоректні дані у файлі!" << endl;
            return 1;
        }
    }
    fin.close();

    // Обчислюємо результати
    vector<double> result(n);
    for (int i = 0; i < n; i++) {
        if (m[i] == 0) {
            cerr << "Помилка: ділення на нуль при m[" << i << "]!" << endl;
            return 1;
        }
        result[i] = x[i] / m[i];
    }

    // Записуємо у вихідний файл
    ofstream fout("output.txt");
    if (!fout.is_open()) {
        cerr << "Помилка: неможливо відкрити output.txt для запису!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fout << result[i] << endl;
    }
    fout.close();

    cout << "Результати успішно записані у файл output.txt" << endl;
    return 0;
}
