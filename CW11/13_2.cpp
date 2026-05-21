#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int firstDot = s.find('.');
    int lastDot = s.rfind('.');

    // якщо крапок немає
    if (firstDot == string::npos) {
        // видаляємо пробіли на початку
        int i = 0;
        while (i < s.length() && s[i] == ' ') i++;
        cout << s.substr(i) << endl;
    }
    // якщо тільки одна крапка
    else if (firstDot == lastDot) {
        // видаляємо все до неї (включно)
        cout << s.substr(firstDot + 1) << endl;
    }
    // якщо є дві або більше крапок
    else {
        // видаляємо підрядок між першою та останньою крапкою
        string result = s.substr(0, firstDot + 1) +
                        s.substr(lastDot);
        cout << result << endl;
    }

    return 0;
}