#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> splitIntoWords(const string& sentence) {
    vector<string> words;
    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

string joinWords(const vector<string>& words) {
    string result;

    for (size_t i = 0; i < words.size(); i++) {
        if (i > 0) {
            result += " ";
        }

        result += words[i];
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Vykorystannia: " << argv[0] << " \"rechennia\"" << endl;
        return 0;
    }

    string sentence;

    for (int i = 1; i < argc; i++) {
        if (i > 1) {
            sentence += " ";
        }

        sentence += argv[i];
    }

    vector<string> words = splitIntoWords(sentence);

    if (words.empty()) {
        cout << "Pomylka: rechennia ne mozhe buty porozhnim" << endl;
        return 0;
    }

    sort(words.begin(), words.end());

    cout << "Anahramy rechennia:" << endl;

    int count = 0;

    do {
        cout << joinWords(words) << endl;
        count++;
    } while (next_permutation(words.begin(), words.end()));

    cout << "Kilkist anahram = " << count << endl;

    return 0;
}