#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class BoolVector {
private:
    vector<bool> data;

public:
    BoolVector() {}

    BoolVector(int n) {
        data.resize(n);
    }

    BoolVector(const vector<bool>& values) {
        data = values;
    }

    int size() const {
        return data.size();
    }

    void input() {
        int n;

        cout << "Vvedit rozmir vektora: ";
        cin >> n;

        if (n <= 0) {
            throw invalid_argument("rozmir vektora maie buty dodatnim");
        }

        data.clear();

        cout << "Vvedit elementy vektora 0 abo 1:" << endl;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x != 0 && x != 1) {
                throw invalid_argument("elementy vektora maiut buty tilky 0 abo 1");
            }

            data.push_back(x);
        }
    }

    BoolVector conjunction(const BoolVector& other) const {
        if (data.size() != other.data.size()) {
            throw invalid_argument("vektory maiut rizni rozmiry");
        }

        BoolVector result(data.size());

        for (size_t i = 0; i < data.size(); i++) {
            result.data[i] = data[i] && other.data[i];
        }

        return result;
    }

    BoolVector disjunction(const BoolVector& other) const {
        if (data.size() != other.data.size()) {
            throw invalid_argument("vektory maiut rizni rozmiry");
        }

        BoolVector result(data.size());

        for (size_t i = 0; i < data.size(); i++) {
            result.data[i] = data[i] || other.data[i];
        }

        return result;
    }

    BoolVector negation() const {
        BoolVector result(data.size());

        for (size_t i = 0; i < data.size(); i++) {
            result.data[i] = !data[i];
        }

        return result;
    }

    int countOnes() const {
        int count = 0;

        for (bool x : data) {
            if (x) {
                count++;
            }
        }

        return count;
    }

    int countZeros() const {
        return data.size() - countOnes();
    }

    void print() const {
        for (bool x : data) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        BoolVector A, B;

        cout << "Vektor A:" << endl;
        A.input();

        cout << "Vektor B:" << endl;
        B.input();

        cout << endl;

        cout << "A = ";
        A.print();

        cout << "B = ";
        B.print();

        cout << "A AND B = ";
        A.conjunction(B).print();

        cout << "A OR B = ";
        A.disjunction(B).print();

        cout << "NOT A = ";
        A.negation().print();

        cout << "NOT B = ";
        B.negation().print();

        cout << "Kilkist odynyts u A: " << A.countOnes() << endl;
        cout << "Kilkist nuliv u A: " << A.countZeros() << endl;

        cout << "Kilkist odynyts u B: " << B.countOnes() << endl;
        cout << "Kilkist nuliv u B: " << B.countZeros() << endl;
    }
    catch (const exception& e) {
        cout << "Pomylka: " << e.what() << endl;
    }

    return 0;
}
