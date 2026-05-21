#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void inputVector(vector<int>& v, int n, const string& name) {
    cout << "Vvedit elementy vektora " << name << ":" << endl;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void printVector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n, m;

    cout << "Vvedit kilkist elementiv V1: ";
    cin >> n;

    cout << "Vvedit kilkist elementiv V2: ";
    cin >> m;

    if (n < 0 || m < 0) {
        cout << "Pomylka: kilkist elementiv ne mozhe buty vid'iemnoiu" << endl;
        return 0;
    }

    vector<int> V1, V2;

    inputVector(V1, n, "V1");
    inputVector(V2, m, "V2");

    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());

    vector<int> result;

    set_union(
        V1.begin(), V1.end(),
        V2.begin(), V2.end(),
        back_inserter(result)
    );

    cout << "Rezultat u poriadku nezrostannia:" << endl;
    printVector(result);

    return 0;
}
