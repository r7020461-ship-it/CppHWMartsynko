#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

struct ClientRecord {
    int clientCode;
    int year;
    int month;
    int hours;
};

int main() {
    string fileName;

    cout << "Vvedit nazvu failu: ";
    cin >> fileName;

    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Pomylka: ne vdalosia vidkryty fail \"" << fileName << "\"" << endl;
        return 0;
    }

    vector<ClientRecord> records;
    ClientRecord current;

    while (file >> current.clientCode >> current.year >> current.month >> current.hours) {
        records.push_back(current);
    }

    if (!file.eof()) {
        cout << "Pomylka: nekorektni dani u faili" << endl;
        return 0;
    }

    if (records.empty()) {
        cout << "Pomylka: fail porozhnii abo ne mistyt danykh" << endl;
        return 0;
    }

    int minHours = records[0].hours;

    for (const ClientRecord& record : records) {
        if (record.hours < minHours) {
            minHours = record.hours;
        }
    }

    cout << "Elementy z minimalnoiu kilkistiu zaniat:" << endl;
    cout << "Kod klienta  Rik  Misiats  Kilkist zaniat" << endl;

    for (const ClientRecord& record : records) {
        if (record.hours == minHours) {
            cout << record.clientCode << " "
                 << record.year << " "
                 << record.month << " "
                 << record.hours << endl;
        }
    }

    return 0;
}