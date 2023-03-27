#include <iostream>
#include "E9.8.h"

using namespace std;

int main() {
    // create a new student named Alice
    Student alice("Alice");

    // add some quiz scores for Alice
    alice.add_quiz(80);
    alice.add_quiz(90);
    alice.add_quiz(95);

    // print out Alice's information
    cout << "Name: " << alice.get_name() << endl;
    cout << "Total Score: " << alice.get_total_score() << endl;
    cout << "Average Score: " << alice.get_average_score() << endl;

    return 0;
}
