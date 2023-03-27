#include <iostream>
#include "P9.16.h"  // assuming Letter class is defined in Letter.h

using namespace std;

int main() {
    // create a letter from "John" to "Mary"
    Letter letter("John", "Mary");

    // add some lines to the letter
    letter.add_line("How are you doing?");
    letter.add_line("I hope this letter finds you well.");
    letter.add_line("I wanted to let you know that I'm thinking of you.");

    // print the text of the letter
    cout << letter.get_text() << endl;

    return 0;
}
