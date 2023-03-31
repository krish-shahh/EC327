#include <iostream>
#include <string>

using namespace std;

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

int main() {
    Student s("John Smith", "01/01/2000", "Computer Science");
    s.display();

    cout << endl;

    Instructor i("Jane Doe", "02/02/1980", 75000.0);
    i.display();

    return 0;
}
