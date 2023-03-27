#include <iostream>
using namespace std;

class DoubleLink : public SimpleLink {
 public:
  // CONSTRUCTORS
  DoubleLink(int thePayload=0) : SimpleLink(thePayload), prev(nullptr) {}
  DoubleLink(const int * const data, unsigned int size):SimpleLink(data, size), prev(nullptr) {}

  // ACCESSORS / GETTERS
  DoubleLink *getPrev() const { return prev; }

  // SETTERS
  void setPrev(DoubleLink *item) { prev = item; }

  // OVERRIDDEN METHODS
  DoubleLink *getNext() const override { return static_cast<DoubleLink *>(next); }
  DoubleLink& getLast() override;
  int countLinks() override;

  // NEW METHODS
  DoubleLink& getFirst();

 protected:
  DoubleLink *prev; // the previous link in the list
};

DoubleLink& DoubleLink::getLast() {
  if (next != nullptr) {
    return getNext()->getLast();
  }
  return static_cast<DoubleLink&>(*this);
}

int DoubleLink::countLinks() {
  if (next != nullptr) {
    return 1 + getNext()->countLinks();
  }
  return 1;
}

DoubleLink& DoubleLink::getFirst() {
  DoubleLink *curr = this;
  while (curr->prev != nullptr) {
    curr = curr->prev;
  }
  return *curr;
}
