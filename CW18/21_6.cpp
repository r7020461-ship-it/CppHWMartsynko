#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Sum {
private:
    T total;

public:
    Sum() {
        total = T();
    }

    void operator()(const T& value) {
        total += value;
    }

    T getSum() const {
        return total;
    }
};

int main() {
    int n;

    cout << "Vvedit kilkist elementiv: ";
    cin >> n;

    if (n <= 0) {
        cout << "Pomylka: kilkist elementiv maie buty dodatnoiu" << endl;
        return 0;
    }

    vector<double> numbers;

    cout << "Vvedit elementy:" << endl;

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        numbers.push_back(x);
    }

    Sum<double> result = for_each(numbers.begin(), numbers.end(), Sum<double>());

    cout << "Suma elementiv = " << result.getSum() << endl;

    return 0;
}