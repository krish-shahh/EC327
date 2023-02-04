#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char flipCoin() {
  // Randomly return 'H' or 'T'
  return (rand() % 2 == 0) ? 'H' : 'T';
}

pair<int, int> event1() {
  int heads = 0;
  int tails = 0;

  char prev = flipCoin();
  heads += (prev == 'H');
  tails += (prev == 'T');
  char current = flipCoin();
  heads += (current == 'H');
  tails += (current == 'T');
  while (!(prev == 'H' && current == 'T')) {
    // Keep flipping the coin until we see 'HT'
    prev = current;
    current = flipCoin();
    heads += (current == 'H');
    tails += (current == 'T');
  }

  return make_pair(heads, tails);
}

pair<int, int> event2() {
  int heads = 0;
  int tails = 0;

  char prev = flipCoin();
  heads += (prev == 'T');
  tails += (prev == 'T');
  char current = flipCoin();
  heads += (current == 'T');
  tails += (current == 'T');
  while (!(prev == 'T' && current == 'T')) {
    // Keep flipping the coin until we see 'TT'
    prev = current;
    current = flipCoin();
    heads += (current == 'H');
    tails += (current == 'T');
  }

  return make_pair(heads, tails);
}

int main() {
  srand(time(0));

  int event1Heads = 0;
  int event1Tails = 0;
  int event2Heads = 0;
  int event2Tails = 0;
  for (int i = 0; i < 2622; i++) {
    pair<int, int> event1Result = event1();
    pair<int, int> event2Result = event2();
    event1Heads += event1Result.first;
    event1Tails += event1Result.second;
    event2Heads += event2Result.first;
    event2Tails += event2Result.second;
  }

  cout << "Total number of heads for Event 1: " << event1Heads << endl;
  cout << "Total number of tails for Event 1: " << event1Tails << endl;
  cout << "Total number of heads for Event 2: " << event2Heads << endl;
  cout << "Total number of tails for Event 2: " << event2Tails << endl;

  return 0;
}
