#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Vykorystannia: " << argv[0] << " slovo" << endl;
        return 0;
    }

    string word = argv[1];

    if (word.empty()) {
        cout << "Pomylka: slovo ne mozhe buty porozhnim" << endl;
        return 0;
    }

    sort(word.begin(), word.end());

    cout << "Anahramy slova:" << endl;

    int count = 0;

    do {
        cout << word << endl;
        count++;
    } while (next_permutation(word.begin(), word.end()));

    cout << "Kilkist anahram = " << count << endl;

    return 0;
}