#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int colon = s.find(':');

    // якщо немає двокрапки
    if (colon == string::npos) {
        cout << s << endl;
        return 0;
    }

    // шукаємо кому після двокрапки
    int comma = s.find(',', colon + 1);

    // якщо коми немає
    if (comma == string::npos) {
        cout << s.substr(colon + 1) << endl;
    } else {
        cout << s.substr(colon + 1, comma - colon - 1) << endl;
    }

    return 0;
}
