#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int i = 0;
    int minLen = 1e9;

    string word, shortestFirst = "", shortestLast = "";

    // перший прохід — знайти мінімальну довжину
    while (i < s.length()) {
        if (s[i] == ' ') {
            i++;
        } else {
            int start = i;

            while (i < s.length() && s[i] != ' ')
                i++;

            int len = i - start;
            if (len < minLen) {
                minLen = len;
            }
        }
    }

    // другий прохід — знайти слова
    i = 0;
    bool firstFound = false;

    cout << "Vsi naikorotshi slova: ";

    while (i < s.length()) {
        if (s[i] == ' ') {
            i++;
        } else {
            int start = i;

            while (i < s.length() && s[i] != ' ')
                i++;

            int len = i - start;
            string w = s.substr(start, len);

            if (len == minLen) {
                // а) перше
                if (!firstFound) {
                    shortestFirst = w;
                    firstFound = true;
                }

                // б) останнє
                shortestLast = w;

                // в) всі
                cout << w << " ";
            }
        }
    }

    cout << endl;
    cout << "a) Pershe: " << shortestFirst << endl;
    cout << "b) Ostanne: " << shortestLast << endl;

    return 0;
}