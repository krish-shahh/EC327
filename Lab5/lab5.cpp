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
    Student s("John Smith", "01/01/2000", "Computer Science");
    s.display();

    cout << endl;

    Instructor i("Jane Doe", "02/02/1980", 75000.0);
    i.display();

    cout << endl;

}

void p101() {

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
    string s = "rum";
    vector<string> substrings = generate_substrings(s);
    for (string sub : substrings) {
        cout << "\"" << sub << "\" ";
    }
    cout << endl;
}

int main() {
    e107();
    e1112();
    e1116();
    return 0;
}