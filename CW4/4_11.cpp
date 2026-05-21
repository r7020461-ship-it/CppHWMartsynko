#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
    string s;
    double x;
    double sum = 0, product = 1;
    int count = 0;

    while (true) {
        cout << "a[" << count << "]=";
        getline(cin, s);

        stringstream ss(s);

        if (!(ss >> x)) break;

        sum += x;
        product *= x;
        count++;
    }

    if (count == 0) {
        cout << "Chysel ne vvedeno" << endl;
        return 0;
    }

    double arithmetic = sum / count;
    double geometric = pow(product, 1.0 / count);

    cout << "Suma = " << sum << endl;
    cout << "Serednie aryfmetychne = " << arithmetic << endl;
    cout << "Serednie geometrychne = " << geometric << endl;

    return 0;
}