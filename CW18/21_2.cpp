#include <iostream>
#include <list>

using namespace std;

void inputList(list<int>& numbers, int n) {
    cout << "Vvedit elementy spysku:" << endl;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }
}

void printList(const list<int>& numbers) {
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;
}

void rearrangeList(list<int>& numbers, int X) {
    auto border = numbers.begin();
    auto it = numbers.begin();

    while (it != numbers.end()) {
        auto current = it;
        ++it;

        if (*current <= X) {
            if (current == border) {
                ++border;
            } else {
                numbers.splice(border, numbers, current);
            }
        }
    }
}

int main() {
    int n, X;

    cout << "Vvedit kilkist elementiv spysku: ";
    cin >> n;

    if (n < 0) {
        cout << "Pomylka: kilkist elementiv ne mozhe buty vid'iemnoiu" << endl;
        return 0;
    }

    list<int> List;

    inputList(List, n);

    cout << "Vvedit X: ";
    cin >> X;

    cout << "Pochatkovyi spysok:" << endl;
    printList(List);

    rearrangeList(List, X);

    cout << "Spysok pislia perestanovky:" << endl;
    printList(List);

    return 0;
}