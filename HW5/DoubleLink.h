#include "SimpleLink.h"
#include <iostream>

using namespace std;

class DoubleLink : public SimpleLink {
public:
    DoubleLink(int thePayload=0) : SimpleLink(thePayload) {
      payload = thePayload;
      next = nullptr;
      prev = nullptr;
    }
    DoubleLink(const int * const data, unsigned int size) : SimpleLink(data, size) {
      static int size1 = size;
      payload = data[0];
      if(size!=1) {
        next = new DoubleLink(data+1, size-1);
        next->prev = this;
        if(size1 == size) {
          prev = nullptr;
        }
      }
      next = nullptr;
    }

    DoubleLink *getPrev() const { return prev; }
    void setPrev(DoubleLink *item) { prev = item; }
    // overrides
    DoubleLink *getNext() const {return next;}
    void setNext(DoubleLink *item) {next = item;}

    DoubleLink& getFirst() {
        DoubleLink *i;
        if(this->getPrev()) {
          i = this->getPrev();
        }
        else {
          return *this;
        }
        while(i->getPrev()) {
          i = i->getPrev();
        }
        return *i;
    }

    DoubleLink& getLast() {
        DoubleLink *i;
        if(this->getNext()) {
          i = this->getNext();
        }
        else {
          return *this;
        }
        while(i->getNext()) {
          i = i->getNext();
        }
        return *i;
    }

    DoubleLink& operator+=(DoubleLink &otherLink) {
      this->getLast().next = &otherLink;
      otherLink.setPrev(&(this->getLast()));
      return *this;
    }


    friend ostream & operator<< (ostream &out, const DoubleLink &startLink) {
    DoubleLink curr = startLink;
    while (curr.getNext()) {
      out << curr.getPayload() << "->";
      curr = *curr.getNext();
    }
    out << curr.getPayload() << "->";
    return out;
  }

protected:
    DoubleLink *prev;
    DoubleLink *next;
};
