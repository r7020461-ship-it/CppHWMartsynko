#include <iostream>
#include <string>
using namespace std;

bool isArticle(const string& w) {
    return w == "a" || w == "an" || w == "the";
}

int main() {
    string s;
    getline(cin, s);

    string result = "";
    string word = "";
    bool afterArticle = false;

    for (int i = 0; i <= s.length(); i++) {
        if (i < s.length() && s[i] != ' ') {
            word += s[i];
        } else {
            // обробка слова
            if (afterArticle && word.length() > 0) {
                word[0] = tolower(word[0]);
            }

            result += word;

            // перевіряємо чи це артикль
            if (isArticle(word)) {
                afterArticle = true;
            } else {
                afterArticle = false;
            }

            if (i < s.length()) result += " ";

            word = "";
        }
    }

    cout << result << endl;

    return 0;
}
