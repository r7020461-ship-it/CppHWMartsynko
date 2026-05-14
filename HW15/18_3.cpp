#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

template <class T>
class BlackBox {
private:
    T arr[100];
    int size;

public:
    BlackBox() {
        size = 0;
    }

    BlackBox(T a[], int n) {
        if (n > 100) n = 100;
        size = n;

        for (int i = 0; i < size; i++)
            arr[i] = a[i];
    }

    void push(T value) {
        if (size >= 100)
            throw runtime_error("BlackBox переповнений!");

        arr[size++] = value;
    }

    T pop() {
        if (size == 0)
            throw runtime_error("BlackBox порожній!");

        int index = rand() % size;
        T value = arr[index];

        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
        return value;
    }

    T xpop() const {
        if (size == 0)
            throw runtime_error("BlackBox порожній!");

        int index = rand() % size;
        return arr[index];
    }

    int count() const {
        return size;
    }
};

int main() {
    srand(time(0));

    try {
        BlackBox<int> box;

        box.push(10);
        box.push(20);
        box.push(30);
        box.push(40);

        cout << "Випадковий елемент без видалення: "
             << box.xpop() << endl;

        cout << "Випадковий елемент з видаленням: "
             << box.pop() << endl;

        cout << "Кількість елементів: "
             << box.count() << endl;
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}
