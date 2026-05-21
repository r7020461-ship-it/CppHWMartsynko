#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Address {
protected:
    string city, street;
    int house, flat;

public:
    Address(string c = "", string s = "", int h = 0, int f = 0)
        : city(c), street(s), house(h), flat(f) {}

    virtual void input() {
        cout << "Місто: ";
        cin >> city;
        cout << "Вулиця: ";
        cin >> street;
        cout << "Номер будинку: ";
        cin >> house;
        cout << "Номер квартири: ";
        cin >> flat;
    }

    virtual void print(ostream& out) const {
        out << city << ", вул. " << street
            << ", буд. " << house
            << ", кв. " << flat;
    }

    string getCity() const {
        return city;
    }

    virtual bool isInternational() const {
        return false;
    }

    virtual string getCountry() const {
        return "";
    }

    virtual string getIndex() const {
        return "";
    }

    virtual ~Address() {}
};

class InternationalAddress : public Address {
private:
    string country;
    string postalCode;

public:
    void input() override {
        Address::input();
        cout << "Країна: ";
        cin >> country;
        cout << "Поштовий код: ";
        cin >> postalCode;
    }

    void print(ostream& out) const override {
        Address::print(out);
        out << ", країна: " << country
            << ", поштовий код: " << postalCode;
    }

    bool isInternational() const override {
        return true;
    }

    string getCountry() const override {
        return country;
    }

    string getIndex() const override {
        return postalCode;
    }
};

int main() {
    int n;
    cout << "Введіть кількість адрес: ";
    cin >> n;

    Address** arr = new Address*[n];

    for (int i = 0; i < n; i++) {
        int type;
        cout << "\n1 - звичайна адреса, 2 - міжнародна: ";
        cin >> type;

        if (type == 2)
            arr[i] = new InternationalAddress();
        else
            arr[i] = new Address();

        arr[i]->input();
    }

    string popularCity;
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (!arr[i]->isInternational()) continue;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j]->getCity() == arr[i]->getCity())
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            popularCity = arr[i]->getCity();
        }
    }

    string country = "", index = "";

    for (int i = 0; i < n; i++) {
        if (arr[i]->getCity() == popularCity && arr[i]->isInternational()) {
            country = arr[i]->getCountry();
            index = arr[i]->getIndex();
            break;
        }
    }

    ofstream fout("addresses.txt");

    fout << "Найпопулярніше місто: " << popularCity << endl;
    fout << "Адреси з цього міста:\n\n";

    for (int i = 0; i < n; i++) {
        if (arr[i]->getCity() == popularCity) {
            arr[i]->print(fout);

            if (!arr[i]->isInternational()) {
                fout << ", країна: " << country
                     << ", поштовий код: " << index;
            }

            fout << endl;
        }
    }

    fout.close();

    cout << "\nДані записано у файл addresses.txt" << endl;

    for (int i = 0; i < n; i++)
        delete arr[i];

    delete[] arr;

    return 0;
}
