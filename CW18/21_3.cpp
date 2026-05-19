#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumLargestK(vector<int> v, int k) {
    if (k < 0 || k > static_cast<int>(v.size())) {
        return 0;
    }

    sort(v.begin(), v.end(), greater<int>());

    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += v[i];
    }

    return sum;
}

vector<int> smallestK(vector<int> v, int k) {
    if (k < 0 || k > static_cast<int>(v.size())) {
        return vector<int>();
    }

    sort(v.begin(), v.end());

    vector<int> result;

    for (int i = 0; i < k; i++) {
        result.push_back(v[i]);
    }

    return result;
}

void inputVector(vector<int>& v, int n) {
    cout << "Vvedit elementy vektora:" << endl;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void printVector(const vector<int>& v) {
    if (v.empty()) {
        cout << "Porozhnii masyv" << endl;
        return;
    }

    for (int x : v) {
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    int n, k;

    cout << "Vvedit rozmir vektora n: ";
    cin >> n;

    if (n < 0) {
        cout << "Pomylka: rozmir vektora ne mozhe buty vid'iemnym" << endl;
        return 0;
    }

    vector<int> numbers;

    inputVector(numbers, n);

    cout << "Vvedit k: ";
    cin >> k;

    int sum = sumLargestK(numbers, k);
    vector<int> minNumbers = smallestK(numbers, k);

    cout << "Suma naibilshykh " << k << " chysel = " << sum << endl;

    cout << k << " naimenshykh chysel:" << endl;
    printVector(minNumbers);

    return 0;
}