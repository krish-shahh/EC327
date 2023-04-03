#include <iostream>
#include <vector>

using namespace std;

void e132();
void e133();
void p131();

ostream& operator<<(ostream& os, const vector<int>& vec) {
    os << "[";
    for (int i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

void e132() {
    vector<int> v{1, 2, 3, 4, 5};
    cout << v << endl;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

void e133() {
    vector<int> v1{1, 2, 3, 4, 5};
    vector<double> v2{1.1, 2.2, 3.3, 4.4, 5.5};
    vector<string> v3{"hello", "world", "!"};

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
}

class Money {
public:
    int dollars;
    int cents;

    // Constructors
    Money() : dollars(0), cents(0) {}
    Money(int dollars, int cents) : dollars(dollars), cents(cents) {}
    Money(double amount) {
        dollars = static_cast<int>(amount);
        cents = static_cast<int>((amount - dollars) * 100);
    }

    // Arithmetic operators
    Money operator+(const Money& other) const {
        Money result;
        result.dollars = dollars + other.dollars;
        result.cents = cents + other.cents;
        if (result.cents >= 100) {
            result.dollars += 1;
            result.cents -= 100;
        }
        return result;
    }

    Money operator-(const Money& other) const {
        Money result;
        result.dollars = dollars - other.dollars;
        result.cents = cents - other.cents;
        if (result.cents < 0) {
            result.dollars -= 1;
            result.cents += 100;
        }
        return result;
    }

    Money operator*(double n) const {
        double amount = dollars + cents / 100.0;
        amount *= n;
        return Money(amount);
    }

    // Comparison operators
    bool operator==(const Money& other) const {
        return dollars == other.dollars && cents == other.cents;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
    }

    bool operator<(const Money& other) const {
        if (dollars < other.dollars) {
            return true;
        } else if (dollars == other.dollars && cents < other.cents) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(const Money& other) const {
        return !(*this < other) && !(*this == other);
    }

    bool operator<=(const Money& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const Money& other) const {
        return (*this > other) || (*this == other);
    }

    // Input and output operators
    friend istream& operator>>(istream& is, Money& money) {
        char dollarSign;
        is >> dollarSign >> money.dollars >> money.cents;
        if (dollarSign != '$') {
            is.setstate(ios::failbit);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Money& money) {
        os << "$" << money.dollars << "." << money.cents;
        return os;
    }

    // % operator
    friend Money operator%(double n, const Money& m) {
        double percent = n / 100.0;
        double amount = m.dollars + m.cents / 100.0;
        amount *= percent;
        return Money(amount);
    }
};

void p131() {
    Money a(10, 50);
    Money b(5, 75);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;

    cout << "a == b ? " << (a == b ? "true" : "false") << endl;
    cout << "a != b ? " << (a != b ? "true" : "false") << endl;
    cout << "a < b ? " << (a < b ? "true" : "false") << endl;
    cout << "a > b ? " << (a > b ? "true" : "false") << endl;
    cout << "a <= b ? " << (a <= b ? "true" : "false") << endl;
    cout << "a >= b ? " << (a >= b ? "true" : "false") << endl;

    cout << "Enter a dollar amount: ";
    Money c;
    cin >> c.dollars;
    cout << "Enter a cents amount: ";
    cin >> c.cents;
    cout << "You entered: " << c << endl;

    double percent = 25.0;
    cout << percent << "% of " << b << " = " << percent % b << endl;
}

int main() {
    e132();
    e133();
    p131();
}