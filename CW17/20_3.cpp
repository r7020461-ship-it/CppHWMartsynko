#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x;
    int y;
};

struct Segment {
    Point a;
    Point b;
    double length;
};

void skipSpaces(const string& s, size_t& i) {
    while (i < s.size() && isspace(static_cast<unsigned char>(s[i]))) {
        i++;
    }
}

bool readInteger(const string& s, size_t& i, int& value) {
    skipSpaces(s, i);

    int sign = 1;

    if (i < s.size() && s[i] == '-') {
        sign = -1;
        i++;
    }

    if (i >= s.size() || !isdigit(static_cast<unsigned char>(s[i]))) {
        return false;
    }

    int number = 0;

    while (i < s.size() && isdigit(static_cast<unsigned char>(s[i]))) {
        number = number * 10 + (s[i] - '0');
        i++;
    }

    value = sign * number;
    return true;
}

bool readPoint(const string& s, size_t& i, Point& p) {
    skipSpaces(s, i);

    if (i >= s.size() || s[i] != '(') {
        return false;
    }
    i++;

    if (!readInteger(s, i, p.x)) {
        return false;
    }

    skipSpaces(s, i);

    if (i >= s.size() || s[i] != ',') {
        return false;
    }
    i++;

    if (!readInteger(s, i, p.y)) {
        return false;
    }

    skipSpaces(s, i);

    if (i >= s.size() || s[i] != ')') {
        return false;
    }
    i++;

    return true;
}

vector<Point> readPointsFromFile(const string& fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        throw runtime_error("ne vdalosia vidkryty vkhidnyi fail");
    }

    string text, line;

    while (getline(file, line)) {
        text += line + " ";
    }

    vector<Point> points;
    size_t i = 0;

    while (i < text.size()) {
        skipSpaces(text, i);

        if (i >= text.size()) {
            break;
        }

        Point p;

        if (!readPoint(text, i, p)) {
            throw runtime_error("nekorektnyi format danykh u faili");
        }

        points.push_back(p);

        skipSpaces(text, i);

        if (i < text.size() && text[i] == ',') {
            i++;
        }
    }

    return points;
}

double distanceBetweenPoints(const Point& a, const Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

int main() {
    string inputFileName;
    string outputFileName;

    cout << "Vvedit nazvu vkhidnoho failu: ";
    cin >> inputFileName;

    cout << "Vvedit nazvu vykhidnoho failu: ";
    cin >> outputFileName;

    try {
        vector<Point> points = readPointsFromFile(inputFileName);

        if (points.size() < 2) {
            cout << "Pomylka: u faili maie buty ne menshe dvokh tochok" << endl;
            return 0;
        }

        vector<Segment> segments;

        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = i + 1; j < points.size(); j++) {
                Segment segment;
                segment.a = points[i];
                segment.b = points[j];
                segment.length = distanceBetweenPoints(points[i], points[j]);

                segments.push_back(segment);
            }
        }

        sort(segments.begin(), segments.end(),
            [](const Segment& s1, const Segment& s2) {
                return s1.length < s2.length;
            }
        );

        ofstream output(outputFileName);

        if (!output.is_open()) {
            cout << "Pomylka: ne vdalosia stvoryty vykhidnyi fail" << endl;
            return 0;
        }

        output << fixed << setprecision(4);

        for (const Segment& segment : segments) {
            output << "(" << segment.a.x << ", " << segment.a.y << ") - "
                   << "(" << segment.b.x << ", " << segment.b.y << ")"
                   << "  dovzhyna = " << segment.length << endl;
        }

        cout << "Fail \"" << outputFileName << "\" uspishno stvoreno" << endl;
    }
    catch (const exception& e) {
        cout << "Pomylka: " << e.what() << endl;
    }

    return 0;
}