#include <iostream>
#include "P9.2.h"

using namespace std;

int main() {
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

    return 0;
}
