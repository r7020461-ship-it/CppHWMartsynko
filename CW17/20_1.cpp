#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

bool isLetter(char c) {
    return isalpha(static_cast<unsigned char>(c));
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

    map<string, int> words;
    string word;
    char c;

    while (file.get(c)) {
        if (isLetter(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                words[word]++;
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        words[word]++;
    }

    if (words.empty()) {
        cout << "U faili nemaie sliv" << endl;
        return 0;
    }

    cout << "Slovo - kilkist vhodzhen:" << endl;

    for (const auto& pair : words) {
        cout << pair.first << " - " << pair.second << endl;
    }

    return 0;
}
