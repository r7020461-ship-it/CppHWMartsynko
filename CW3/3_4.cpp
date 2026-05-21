#include <iostream>
#include <cstdint>
using namespace std;

uint16_t product(uint8_t a, uint8_t b) {
    return static_cast<uint16_t>(a) * static_cast<uint16_t>(b);
}

int main() {
    int x, y;
    cin >> x >> y;

    uint8_t a = x;
    uint8_t b = y;

    uint16_t result = product(a, b);

    cout << result << endl;

    return 0;
}