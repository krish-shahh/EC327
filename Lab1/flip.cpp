/*
Write a program to randomly flips a fair coin until it sees a Heads followed immediately by a Tail [Event 1]; Write a similar program that continues until it sees a Tail followed immediately by a Tail [Event 2]. Run your program 2622 times and report the total number of Heads and Tails for each two events.
*/

#include <iostream>
#include <random>

int main() {
  int event1Heads = 0;
  int event1Tails = 0;
  int event2Heads = 0;
  int event2Tails = 0;
  int numRuns = 1;

  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> coinFlip(0, 1);

  for (int i = 0; i < numRuns; i++) {
    int prev = coinFlip(generator);
    int curr = coinFlip(generator);
    while (prev != 1 || curr != 0) {
      event1Heads += prev;
      event1Tails += curr;
      prev = curr;
      curr = coinFlip(generator);
    }
    event1Heads += prev;
    event1Tails += curr;

    prev = coinFlip(generator);
    curr = coinFlip(generator);
    while (prev != 0 || curr != 0) {
      event2Heads += prev;
      event2Tails += curr;
      prev = curr;
      curr = coinFlip(generator);
    }
    event2Heads += prev;
    event2Tails += curr;
  }

  std::cout << "Event 1: " << event1Heads << " heads, " << event1Tails << " tails" << std::endl;
  std::cout << "Event 2: " << event2Heads << " heads, " << event2Tails << " tails" << std::endl;

  return 0;
}
