/*
Write a program to randomly flips a fair coin until it sees a Heads followed immediately by a Tail [Event 1]; Write a similar program that continues until it sees a Tail followed immediately by a Tail [Event 2]. Run your program 2622 times and report the total number of Heads and Tails for each two events.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int flipCoin() {
  return rand() % 2;
}

int main() {
  srand(time(0));

  int event1Heads = 0, event1Tails = 0, event2Heads = 0, event2Tails = 0;

  for (int i = 0; i < 2622; i++) {
    int prev = flipCoin();
    int current = flipCoin();

    if (prev == 0 && current == 1) {
      event1Heads++;
      event1Tails++;
    } else {
      event1Heads += prev;
      event1Tails += (current == 0 ? 1 : 0);
      prev = current;
      current = flipCoin();

      if (prev == 0 && current == 0) {
        event2Heads += prev;
        event2Tails += current + 2;
      } else {
        event2Heads += prev;
        event2Tails += (current == 0 ? 1 : 0);
      }
    }
  }

  cout << "Event 1: " << event1Heads << " Heads and " << event1Tails << " Tails" << endl;
  cout << "Event 2: " << event2Heads << " Heads and " << event2Tails << " Tails" << endl;

  return 0;
}
