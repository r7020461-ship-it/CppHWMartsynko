#include <iostream>
using namespace std;

struct Date {
    int day, month, year;
};

bool leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int daysInMonth(int m, int y) {
    int d[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && leap(y)) return 29;
    return d[m];
}

Date tomorrow(Date d) {
    d.day++;

    if (d.day > daysInMonth(d.month, d.year)) {
        d.day = 1;
        d.month++;
    }

    if (d.month > 12) {
        d.month = 1;
        d.year++;
    }

    return d;
}

int dayOfWeek(Date d) {
    int q = d.day;
    int m = d.month;
    int y = d.year;

    if (m < 3) {
        m += 12;
        y--;
    }

    int k = y % 100;
    int j = y / 100;

    int h = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    return h; // 0 - субота, 1 - неділя, ...
}

void printWeekDay(int h) {
    string days[] = {
        "Subota", "Nedilia", "Ponedilok", "Vivtorok",
        "Sereda", "Chetver", "Piatnytsia"
    };

    cout << days[h] << endl;
}

int main() {
    Date d;

    cout << "Vvedit datu: ";
    cin >> d.day >> d.month >> d.year;

    Date t = tomorrow(d);

    cout << "Data zavtrashnoho dnia: ";
    cout << t.day << "." << t.month << "." << t.year << endl;

    cout << "Den tyzhnia: ";
    printWeekDay(dayOfWeek(d));

    return 0;
}