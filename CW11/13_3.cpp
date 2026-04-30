#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string result;
    int i = 0;

    while (i < s.length()) {
        // якщо пробіл — просто додаємо
        if (s[i] == ' ') {
            result += s[i];
            i++;
        } else {
            // початок слова
            int start = i;

            while (i < s.length() && s[i] != ' ')
                i++;

            int end = i - 1; // останній символ слова

            // додаємо слово без останньої літери
            if (end > start) {
                result += s.substr(start, end - start);
            }
            // якщо слово з 1 літери — нічого не додаємо
        }
    }

    cout << result << endl;

    return 0;
}