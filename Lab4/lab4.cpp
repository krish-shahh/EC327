#include <iostream>
#include <fstream>
#include <map>
#include "E9.8.h"
#include "P9.2.h"
#include "P9.4.h"
#include "P9.16.h"

using namespace std;

void p88(const string& filename);
void e98();
void p92();
void p94();
void p916();

void p88(const string& filename) {

    ifstream input_file(filename);

    if (!input_file) {
        cout << "Unable to open input file: " << filename << endl;
        return;
    }

    map<string, int> frequency_table;

    char c;
    char last_c = '\0';
    while (input_file.get(c)) {
        if (isalpha(c)) {
            c = toupper(c);
            if (last_c != '\0') {
                string sequence;
                sequence += last_c;
                sequence += c;
                frequency_table[sequence]++;
            }
            last_c = c;
        } else {
            last_c = '\0';
        }
    }

    cout << "Two-Letter Sequence Frequency Table:" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Sequence\tFrequency" << endl;
    cout << "-----------------------------------" << endl;

    int total_sequences = 0;
    for (auto iter = frequency_table.begin(); iter != frequency_table.end(); iter++) {
        cout << iter->first << "\t" << iter->second << endl;
        total_sequences += iter->second;
    }

    cout << "-----------------------------------" << endl;
    cout << "Total\t" << total_sequences << endl;
}

void e98() {
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
}

void p92() {
    // create three people
    Person alice("Alice");
    Person bob("Bob");
    Person charlie("Charlie");

    // befriend some people
    alice.befriend(bob);
    bob.befriend(charlie);
    charlie.befriend(alice);

    // print out each person's friends
    cout << alice.get_friend_names() << endl;
    cout << bob.get_friend_names() << endl;
    cout << charlie.get_friend_names() << endl;

    // unfriend some people
    alice.unfriend(bob);
    charlie.unfriend(alice);

    // print out each person's updated friends
    cout << alice.get_friend_names() << endl;
    cout << bob.get_friend_names() << endl;
    cout << charlie.get_friend_names() << endl;
}

void p94() {
    // create three people
    p94c alice("Alice");
    p94c bob("Bob");
    p94c charlie("Charlie");

    // befriend some people
    alice.befriend(&bob);
    bob.befriend(&charlie);
    charlie.befriend(&alice);

    // print out each person's friends
    cout << alice.get_friend_names() << endl;
    cout << bob.get_friend_names() << endl;
    cout << charlie.get_friend_names() << endl;

    // unfriend some people
    alice.unfriend(&bob);
    charlie.unfriend(&alice);

    // print out each person's updated friends
    cout << alice.get_friend_names() << endl;
    cout << bob.get_friend_names() << endl;
    cout << charlie.get_friend_names() << endl;
}

void p916() {
    // create a letter from "John" to "Mary"
    Letter letter("John", "Mary");

    // add some lines to the letter
    letter.add_line("How are you doing?");
    letter.add_line("I hope this letter finds you well.");
    letter.add_line("I wanted to let you know that I'm thinking of you.");

    // print the text of the letter
    cout << letter.get_text() << endl;
}

int main() {
    p88("foo");
    e98();
    p92();
    p94();
    p916();
    return 0;
}