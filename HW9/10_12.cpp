#include <iostream>
#include <cmath>
using namespace std;

struct Price {
    int grn;
    int kop;
};

int toKop(Price p) {
    return p.grn * 100 + p.kop;
}

void inputPrices(Price a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i].grn >> a[i].kop;
    }
}

void printPrice(Price p) {
    cout << p.grn << " грн " << p.kop << " коп";
}

int cheapest(Price a[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (toKop(a[i]) < toKop(a[index]))
            index = i;
    }
    return index;
}

int mostExpensive(Price a[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (toKop(a[i]) > toKop(a[index]))
            index = i;
    }
    return index;
}

double averagePrice(Price a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += toKop(a[i]);

    return (double)sum / n;
}

void nearAverage(Price a[], int n) {
    double avg = averagePrice(a, n);

    cout << "Tovary, shcho vidrizniaiutsia vid serednoi ne bilshe nizh na 10 hrn:" << endl;

    for (int i = 0; i < n; i++) {
        if (abs(toKop(a[i]) - avg) <= 1000) {
            cout << i + 1 << ") ";
            printPrice(a[i]);
            cout << endl;
        }
    }
}

int main() {
    int N;
    cin >> N;

    Price goods[100];

    inputPrices(goods, N);

    int minIndex = cheapest(goods, N);
    int maxIndex = mostExpensive(goods, N);

    cout << "Naideshevshyi tovar: ";
    printPrice(goods[minIndex]);
    cout << endl;

    cout << "Naidorozhchyi tovar: ";
    printPrice(goods[maxIndex]);
    cout << endl;

    nearAverage(goods, N);

    return 0;
}