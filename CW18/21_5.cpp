#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string text;

    cout << "Vvedit riadok: ";
    getline(cin, text);

    transform(text.begin(), text.end(), text.begin(),
              [](unsigned char c) {
                  return toupper(c);
              });

    cout << "Riadok velykymy literamy:" << endl;
    cout << text << endl;

    return 0;
}