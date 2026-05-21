#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    unsigned int birthYear;

public:
    // введення
    int input() {
        cout << "Введіть ім'я: ";
        cin >> name;

        cout << "Введіть рік народження: ";
        cin >> birthYear;

        if (cin.fail()) return 0;
        return 1;
    }

    // виведення
    void show() const {
        cout << "Ім'я: " << name << ", Рік народження: " << birthYear << endl;
    }

    // перевантаження >>
    friend istream& operator>>(istream& in, Person& p) {
        cout << "Введіть ім'я: ";
        in >> p.name;

        cout << "Введіть рік народження: ";
        in >> p.birthYear;

        return in;
    }

    // перевантаження <<
    friend ostream& operator<<(ostream& out, const Person& p) {
        out << "Ім'я: " << p.name
            << ", Рік народження: " << p.birthYear;
        return out;
    }
};

int main() {
    Person p1;

    // через методи
    p1.input();
    p1.show();

    cout << "\n--- Через оператори ---\n";

    Person p2;
    cin >> p2;
    cout << p2 << endl;

    return 0;
}
