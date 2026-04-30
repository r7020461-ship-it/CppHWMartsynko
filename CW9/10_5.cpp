#include <iostream>
#include <string>
using namespace std;

struct Mountain {
    string name;
    double height;
};

void inputMountains(Mountain a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nazva hory: ";
        cin >> a[i].name;

        cout << "Vysota: ";
        cin >> a[i].height;
    }
}

void printMountains(Mountain a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i].name << " - " << a[i].height << " m" << endl;
    }
}

string highestMountain(Mountain a[], int n) {
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (a[i].height > a[maxIndex].height) {
            maxIndex = i;
        }
    }

    return a[maxIndex].name;
}

void findHeightByName(Mountain a[], int n, string name) {
    for (int i = 0; i < n; i++) {
        if (a[i].name == name) {
            cout << "Vysota hory " << name << " = "
                 << a[i].height << " m" << endl;
            return;
        }
    }

    cout << "Hory z takoiu nazvoiu nemaie" << endl;
}

int main() {
    int N;
    cin >> N;

    Mountain mountains[100];

    inputMountains(mountains, N);

    cout << "\nSpysok hir:" << endl;
    printMountains(mountains, N);

    cout << "\nNaivyshcha vershyna: "
         << highestMountain(mountains, N) << endl;

    string searchName;
    cout << "\nVvedit nazvu hory dlia poshuku: ";
    cin >> searchName;

    findHeightByName(mountains, N, searchName);

    return 0;
}