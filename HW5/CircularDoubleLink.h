#include <iostream>
#include "DoubleLink.h"

class CircularDoubleLink : public DoubleLink {
public:
    CircularDoubleLink(int thePayload=0) : DoubleLink(thePayload) {
        next = this;
        prev = this;
    }

    CircularDoubleLink(const int * const data, unsigned int size) : DoubleLink(data, size) {
        DoubleLink *first = &(this->getFirst());
        DoubleLink *last = &(this->getLast());
        first->setPrev(last);
        last->setNext(first);
    }

    DoubleLink *getPrev() const {
        if (prev == this) {
            return getLast().prev;
        } else {
            return prev;
        }
    }

    void setPrev(DoubleLink *item) {
        if (this == getNext() && item != getLast().prev) {
            last()->setNext(item);
            item->setPrev(last());
        } else {
            prev = item;
        }
    }

    CircularDoubleLink& last() {
        return static_cast<CircularDoubleLink&>(DoubleLink::getLast());
    }

    CircularDoubleLink& operator+=(CircularDoubleLink &otherLink) {
        this->last().next = &otherLink;
        otherLink.setPrev(&(this->last()));
        otherLink.setNext(this);
        this->setPrev(&otherLink);
        return *this;
    }

    friend ostream & operator<< (ostream &out, const CircularDoubleLink &startLink) {
        const CircularDoubleLink* curr = &startLink;
        do {
            out << curr->getPayload() << "->";
            curr = static_cast<const CircularDoubleLink*>(curr->getNext());
        } while (curr != &startLink);
        out << "";
        return out;
    }
};
