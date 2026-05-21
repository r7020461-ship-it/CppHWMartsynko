#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Point {
private:
    double x, y;
    static int count;

public:
    Point() {
        x = 0;
        y = 0;
        count++;
    }

    Point(double xVal, double yVal) {
        x = xVal;
        y = yVal;
        count++;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    static int counter() {
        return count;
    }
};

int Point::count = 0;

double distance(const Point& a, const Point& b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

int main() {
    vector<Point> points;
    char answer;

    do {
        double x, y;

        cout << "Введіть координату x: ";
        cin >> x;

        cout << "Введіть координату y: ";
        cin >> y;

        points.push_back(Point(x, y));

        cout << "Ввести ще вершину? (y/n): ";
        cin >> answer;

    } while (answer != 'n' && answer != 'N');

    double perimeter = 0;

    if (points.size() >= 2) {
        for (int i = 0; i < points.size() - 1; i++) {
            perimeter += distance(points[i], points[i + 1]);
        }

        perimeter += distance(points[points.size() - 1], points[0]);
    }

    cout << "\nКількість вершин багатокутника: " << Point::counter() << endl;
    cout << "Периметр багатокутника: " << perimeter << endl;

    return 0;
}