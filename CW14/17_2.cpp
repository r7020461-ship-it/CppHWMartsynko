#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Human {
protected:
    string pib, gender;
    int age;

public:
    Human(string p = "", string g = "", int a = 0)
        : pib(p), gender(g), age(a) {}

    virtual void input() {
        cout << "ПІБ: ";
        cin.ignore();
        getline(cin, pib);
        cout << "Стать: ";
        getline(cin, gender);
        cout << "Вік: ";
        cin >> age;
    }

    virtual void show() const {
        cout << "ПІБ: " << pib << endl;
        cout << "Стать: " << gender << endl;
        cout << "Вік: " << age << endl;
    }

    virtual string getUniversity() const = 0;

    virtual ~Human() {}
};

class Student : virtual public Human {
protected:
    int course;
    string group, university;

public:
    void input() override {
        Human::input();
        cout << "Курс: ";
        cin >> course;
        cout << "Група: ";
        cin >> group;
        cout << "ВУЗ: ";
        cin.ignore();
        getline(cin, university);
    }

    void show() const override {
        Human::show();
        cout << "Курс: " << course << endl;
        cout << "Група: " << group << endl;
        cout << "ВУЗ: " << university << endl;
    }

    string getUniversity() const override {
        return university;
    }
};

class Teacher : virtual public Human {
protected:
    string university;
    string position;

public:
    void input() override {
        Human::input();
        cout << "ВУЗ: ";
        cin.ignore();
        getline(cin, university);
        cout << "Посада: ";
        getline(cin, position);
    }

    void show() const override {
        Human::show();
        cout << "ВУЗ: " << university << endl;
        cout << "Посада: " << position << endl;
    }

    string getUniversity() const override {
        return university;
    }
};

class Aspirant : public Student, public Teacher {
public:
    void input() override {
        Human::input();

        cout << "Курс: ";
        cin >> course;
        cout << "Група: ";
        cin >> group;

        cout << "ВУЗ: ";
        cin.ignore();
        getline(cin, university);

        Teacher::university = university;

        cout << "Посада: ";
        getline(cin, position);
    }

    void show() const override {
        Human::show();
        cout << "Курс: " << course << endl;
        cout << "Група: " << group << endl;
        cout << "ВУЗ: " << Student::university << endl;
        cout << "Посада: " << position << endl;
    }

    string getUniversity() const override {
        return Student::university;
    }
};

int main() {
    int n;
    cout << "Кількість людей: ";
    cin >> n;

    vector<Human*> people;

    for (int i = 0; i < n; i++) {
        int type;
        cout << "\n1 - Студент, 2 - Викладач, 3 - Аспірант: ";
        cin >> type;

        Human* h;

        if (type == 1)
            h = new Student();
        else if (type == 2)
            h = new Teacher();
        else
            h = new Aspirant();

        h->input();
        people.push_back(h);
    }

    cout << "\n--- Дані про людей ---\n";
    for (Human* h : people) {
        h->show();
        cout << "------------------\n";
    }

    for (Human* h : people)
        delete h;

    return 0;
}