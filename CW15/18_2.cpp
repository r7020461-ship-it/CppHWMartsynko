#include <iostream>
#include <stack>
using namespace std;

template <class T>
class MyStack {
private:
    T arr[100];
    int topIndex;

public:
    MyStack() {
        topIndex = -1;
    }

    void push(T value) {
        if (topIndex < 99)
            arr[++topIndex] = value;
    }

    T pop() {
        return arr[topIndex--];
    }

    bool empty() const {
        return topIndex == -1;
    }
};

int inputNumbers(int numbers[]) {
    int x, count = 0;

    cout << "Вводьте цілі числа, 0 - кінець:\n";
    while (cin >> x && x != 0) {
        numbers[count++] = x;
    }

    return count;
}

int oddToStack(int numbers[], int n, MyStack<int>& st) {
    int oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 != 0) {
            st.push(numbers[i]);
            oddCount++;
        }
    }

    return oddCount;
}

int main() {
    int numbers[100];

    int n = inputNumbers(numbers);

    MyStack<int> myStack;
    int oddCount = oddToStack(numbers, n, myStack);

    cout << "\nКількість введених чисел: " << n << endl;
    cout << "Кількість непарних чисел: " << oddCount << endl;

    cout << "\nНепарні числа у власному стеку:\n";
    while (!myStack.empty()) {
        cout << myStack.pop() << " ";
    }

    stack<int> stlStack;

    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 != 0)
            stlStack.push(numbers[i]);
    }

    cout << "\n\nНепарні числа у STL stack:\n";
    while (!stlStack.empty()) {
        cout << stlStack.top() << " ";
        stlStack.pop();
    }

    MyStack<double> doubleStack;
    doubleStack.push(2.5);
    doubleStack.push(7.8);
    doubleStack.push(1.3);

    cout << "\n\nПеревірка шаблону для double:\n";
    while (!doubleStack.empty()) {
        cout << doubleStack.pop() << " ";
    }

    return 0;
}