#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Vvedit n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n має бути натуральним числом" << endl;
        return 0;
    }

    vector<double> t(n), c(n);

    cout << "Vvedit chasy obslugovuvannia t1 ... tn: ";
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    double endTime = 0.0;

    for (int i = 0; i < n; i++) {
        double arrivalTime = i;
        double startService = max(arrivalTime, endTime);

        c[i] = startService - arrivalTime;
        endTime = startService + t[i];
    }

    int minServiceIndex = 0;
    for (int i = 1; i < n; i++) {
        if (t[i] < t[minServiceIndex]) {
            minServiceIndex = i;
        }
    }

    int maxQueueIndex = 0;
    for (int i = 1; i < n; i++) {
        if (c[i] > c[maxQueueIndex]) {
            maxQueueIndex = i;
        }
    }

    cout << fixed << setprecision(2);

    cout << "Chasy perebuvannia v cherzi c1 ... cn:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "c" << i + 1 << " = " << c[i] << endl;
    }

    cout << "Nomer pokuptsia z naimenshym chasom obslugovuvannia: "
         << minServiceIndex + 1 << endl;

    cout << "Nomer pokuptsia, yakyi proviv u cherzi naibilshe chasu: "
         << maxQueueIndex + 1 << endl;

    return 0;
}
