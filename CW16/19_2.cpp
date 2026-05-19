#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<double> inputVector(int d) {
    vector<double> v(d);

    for (int i = 0; i < d; i++) {
        cin >> v[i];
    }

    return v;
}

double vectorNorm(const vector<double>& v) {
    double sum = 0.0;

    for (double x : v) {
        sum += x * x;
    }

    return sqrt(sum);
}

double sumOfNorms(const vector<vector<double>>& vectors) {
    double result = 0.0;

    for (const auto& v : vectors) {
        result += vectorNorm(v);
    }

    return result;
}

int main() {
    int n, d;

    cout << "Vvedit kilkist vektoriv n: ";
    cin >> n;

    cout << "Vvedit rozmirnist vektoriv d: ";
    cin >> d;

    if (n <= 0 || d <= 0) {
        cout << "n ta d maiut buty naturalnymy chyslamy" << endl;
        return 0;
    }

    vector<vector<double>> vectors;

    cout << "Vvedit " << n << " vektoriv po " << d << " elementiv:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Vektor " << i + 1 << ": ";
        vectors.push_back(inputVector(d));
    }

    double result = sumOfNorms(vectors);

    cout << fixed << setprecision(4);
    cout << "Suma norm vektoriv = " << result << endl;

    return 0;
}