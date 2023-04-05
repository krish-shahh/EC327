#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

void e107();
void p101();
void p102();
void e1112();
void e1116();

class Person {
protected:
    string name;
    string birthday;

public:
    Person(string n, string b) {
        name = n;
        birthday = b;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Birthday: " << birthday << endl;
    }
};

class Student : public Person {
private:
    string major;

public:
    Student(string n, string b, string m) : Person(n, b) {
        major = m;
    }

    void display() {
        Person::display();
        cout << "Major: " << major << endl;
    }
};

class Instructor : public Person {
private:
    float salary;

public:
    Instructor(string n, string b, float s) : Person(n, b) {
        salary = s;
    }

    void display() {
        Person::display();
        cout << "Salary: " << salary << endl;
    }
};

void e107() {
    cout << "Question E10.7: " << endl;
    Student s("Krish Shah", "12/21/2003", "Computer Engineering");
    s.display();

    cout << endl;

    Instructor i("Jane Doe", "02/02/1980", 100000.0);
    i.display();

    cout << endl;

}

class Clock {
public:
    virtual int get_hours() const {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_hour;
    }

    int get_minutes() const {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_min;
    }

    string get_time() const {
        int hours = get_hours();
        int minutes = get_minutes();
        string am_pm = (hours < 12) ? "AM" : "PM";
        if (hours > 12) hours -= 12;
        if (hours == 0) hours = 12;
        char buffer[9];
        sprintf(buffer, "%02d:%02d %s", hours, minutes, am_pm.c_str());
        return string(buffer);
    }
};

class WorldClock : public Clock {
private:
    int time_offset;

public:
    WorldClock(int offset) : time_offset(offset) {}

    int get_hours() const override {
        int hours = Clock::get_hours() + time_offset;
        if (hours >= 24) hours -= 24;
        if (hours < 0) hours += 24;
        return hours;
    }

};

void p101() {
    cout << "Question P10.1: " << endl;
    Clock c;
    cout << "Current (NY) time: " << c.get_time() << endl;

    WorldClock wc(-3); // California is 3 hours behind NY
    cout << "California time: " << wc.get_time() << endl;
    cout << endl;
}

void p102() {

}

int findMax(vector<int> values, int n) {
    // base case
    if (n == 1) {
        return values[0];
    }
    // recursive case
    int max = findMax(values, n-1);
    if (max > values[n-1]) {
        return max;
    } else {
        return values[n-1];
    }
}

void e1112() {
    cout << "Question E11.12: " << endl;
    vector<int> values = {7, 5, 8, 0, 2, 5 , 1, 2};
    int maxVal = findMax(values, values.size());
    cout << "The maximum value is: " << maxVal << endl;
    cout << endl;
}

vector<string> generate_substrings(string s) {
    vector<string> result;
    int n = s.length();

    // iterate through all substrings that start with the first character
    for (int i = 0; i < n; i++) {
        string sub = "";
        // iterate through the remaining characters to form the substring
        for (int j = i; j < n; j++) {
            sub += s[j];
            result.push_back(sub);
        }
    }

    return result;
}

void e1116() {
    cout << "Question E11.16: " << endl;
    string s = "rum";
    vector<string> substrings = generate_substrings(s);
    for (string sub : substrings) {
        cout << "\"" << sub << "\" ";
    }
    cout << endl;
}

int main() {
    e107();
    p101();
    e1112();
    e1116();
    return 0;
}