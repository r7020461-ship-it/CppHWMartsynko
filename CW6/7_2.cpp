#include <iostream>
using namespace std;

int main() {
    int a[4] = {5, 112, 4, 3};

    for (int i = 3; i >= 0; i--) {
        cout << a[i];
        if (i != 0) cout << ",";
    }

    return 0;
}