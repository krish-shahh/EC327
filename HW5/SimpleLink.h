#include <iostream>
using namespace std;

class SimpleLink {
 public:
  SimpleLink(int thePayload=0) : payload(thePayload), next(nullptr) {}
  SimpleLink(const int * const data, unsigned int size):payload(data[0]) {
    if (size!=1)
      next = new SimpleLink(data+1,size-1);
    else
      next = nullptr;
  }
 
  int getPayload() const { return payload; }
  SimpleLink *getNext() const { return next; }
  void setPayload(int newPayload) { payload = newPayload; }
  void setNext(SimpleLink *item) { next = item; }
  
  SimpleLink& getLast() {
    SimpleLink* curr = this;
    while (curr->getNext() != nullptr) {
      curr = curr->getNext();
    }
    return *curr;
  }
  
  int countLinks() {
    int count = 0;
    SimpleLink* curr = this;
    while (curr != nullptr) {
      count++;
      curr = curr->getNext();
    }
    return count;
  }
  
  SimpleLink& operator+=(SimpleLink& otherLink) {
    SimpleLink& last = getLast();
    last.setNext(&otherLink);
    return *this;
  }
  
  friend ostream & operator<< (ostream &out, const SimpleLink &startLink) {
    const SimpleLink* curr = &startLink;
    while (curr != nullptr) {
      out << curr->getPayload() << "->";
      curr = curr->getNext();
    }
    out << "nullptr";
    return out;
  }
 
 private:
  int payload;
  SimpleLink *next;
};
