#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>
#include <iterator>

using namespace std;

class ClockGenerator {
public:
    clock_t operator()() const {
        return clock();
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

    list<clock_t> values;

    generate_n(back_inserter(values), n, ClockGenerator());

    values.sort();
    values.unique();

    cout << "Spysok bez dublikativ:" << endl;

    copy(values.begin(), values.end(), ostream_iterator<clock_t>(cout, "\n"));

    return 0;
}