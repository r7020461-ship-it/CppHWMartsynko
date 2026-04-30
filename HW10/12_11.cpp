#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int digitsAfterDot(string s) {
    int pos = s.find('.');
    if (pos == -1) return 0;
    return s.size() - pos - 1;
}

int main() {
    ifstream fin("input.txt");

    vector<double> numbers;
    string part;
    int maxPrecision = 0;

    while (getline(fin, part, ';')) {
        double x = stod(part);
        numbers.push_back(abs(x));

        maxPrecision = max(maxPrecision, digitsAfterDot(part));
    }

    fin.close();

    ofstream fout("input.txt");

    for (double x : numbers) {
        fout << setw(maxPrecision + 5)
             << fixed << setprecision(maxPrecision)
             << x << endl;
    }

    fout.close();

    return 0;
}
