#include <iostream>
using namespace std;

int main() {
    int a[5] = {3, -7, 10, 0, 5};

    double x;
    cin >> x;

    int count = 0;

    for (int i = 0; i < 5; i++) {
        if (a[i] < x) {
            count++;
        }
    }

    cout << "Kilkist = " << count << endl;

    return 0;
}
