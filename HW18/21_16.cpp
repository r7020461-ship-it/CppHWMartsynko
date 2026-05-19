#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename InputIterator, typename OutputIterator, typename UnaryOperation, typename Predicate>
OutputIterator transform_if(InputIterator first,
                            InputIterator last,
                            OutputIterator result,
                            UnaryOperation operation,
                            Predicate predicate) {
    while (first != last) {
        if (predicate(*first)) {
            *result = operation(*first);
            ++result;
        }

        ++first;
    }

    return result;
}

bool isEven(int x) {
    return x % 2 == 0;
}

int square(int x) {
    return x * x;
}

void printVector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    int n;

    cout << "Vvedit kilkist elementiv: ";
    cin >> n;

    if (n <= 0) {
        cout << "Pomylka: kilkist elementiv maie buty dodatnoiu" << endl;
        return 0;
    }

    vector<int> numbers(n);

    cout << "Vvedit elementy:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<int> result(n);

    vector<int>::iterator newEnd = transform_if(
        numbers.begin(),
        numbers.end(),
        result.begin(),
        square,
        isEven
    );

    result.erase(newEnd, result.end());

    cout << "Pochatkovyi vektor:" << endl;
    printVector(numbers);

    cout << "Rezultat transform_if:" << endl;
    printVector(result);

    return 0;
}
