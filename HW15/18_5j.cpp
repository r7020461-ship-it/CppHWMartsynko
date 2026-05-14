#include <iostream>
using namespace std;

template <class T>
class Array {
private:
    T* a;
    int n;

public:
    Array(int size) {
        n = size;
        a = new T[n];
    }

    ~Array() {
        delete[] a;
    }

    void input() {
        for (int i = 0; i < n; i++) {
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }

    void output() const {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    // пункт ж — сортування Шелла
    void shellSort() {
        for (int step = n / 2; step > 0; step /= 2) {
            for (int i = step; i < n; i++) {
                T temp = a[i];
                int j;

                for (j = i; j >= step && a[j - step] > temp; j -= step) {
                    a[j] = a[j - step];
                }

                a[j] = temp;
            }
        }
    }
};

int main() {
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    Array<int> arr(n);

    cout << "Введіть елементи масиву:\n";
    arr.input();

    cout << "Початковий масив:\n";
    arr.output();

    arr.shellSort();

    cout << "Масив після сортування Шелла:\n";
    arr.output();

    return 0;
}