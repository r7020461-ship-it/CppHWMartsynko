#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

bool readInteger(const string& line, int& number) {
    stringstream ss(line);
    long long value;
    char extra;

    ss >> ws;

    if (!(ss >> value)) {
        return false;
    }

    ss >> ws;

    if (ss.get(extra)) {
        return false;
    }

    if (value < INT_MIN || value > INT_MAX) {
        return false;
    }

    number = static_cast<int>(value);
    return true;
}

int main() {
    string fileName;

    cout << "Vvedit nazvu failu: ";
    cin >> fileName;

    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Pomylka: ne vdalosia vidkryty fail \"" << fileName << "\"" << endl;
        return 0;
    }

    vector<int> V;
    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;

        int number;

        if (!readInteger(line, number)) {
            cout << "Pomylka: nekorektni dani u riadku " 
                 << lineNumber << ": \"" << line << "\"" << endl;
            return 0;
        }

        V.push_back(number);
    }

    if (V.empty()) {
        cout << "Pomylka: fail ne mistyt tsilykh chysel" << endl;
        return 0;
    }

    cout << "Chysla u vykhidnomu poriadku:" << endl;

    for (int x : V) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
