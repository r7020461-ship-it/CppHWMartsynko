#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

using Element = pair<int, double>;

void printSet(const set<Element>& numbers) {
    for (const auto& element : numbers) {
        cout << element.second << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Vvedit kilkist chysel n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Pomylka: n maie buty naturalnym chyslom" << endl;
        return 0;
    }

    set<Element> numbers;

    cout << "Vvedit chysla:" << endl;

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        numbers.insert({i, x});
    }

    cout << fixed << setprecision(4);

    cout << "Pochatkovyi riad:" << endl;
    printSet(numbers);

    int stage = 1;

    while (numbers.size() > 1) {
        set<Element> nextNumbers;
        auto it = numbers.begin();
        int newIndex = 0;

        while (it != numbers.end()) {
            double first = it->second;
            ++it;

            if (it != numbers.end()) {
                double second = it->second;
                ++it;

                nextNumbers.insert({newIndex, first + second});
            } else {
                nextNumbers.insert({newIndex, first});
            }

            newIndex++;
        }

        numbers = nextNumbers;

        cout << "Etap " << stage << ":" << endl;
        printSet(numbers);

        stage++;
    }

    cout << "Ostatochnyi rezultat = " << numbers.begin()->second << endl;

    return 0;
}