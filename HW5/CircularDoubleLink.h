class CircularDoubleLink : public DoubleLink {
public:
    CircularDoubleLink(int value, CircularDoubleLink* prev = nullptr, CircularDoubleLink* next = nullptr)
        : DoubleLink(value, prev, next), lastLink(nullptr) {
        if (next == nullptr && prev == nullptr) {
            setNext(this);
            setPrev(this);
        }
    }

    // override setNext and setPrev to update lastLink
    void setNext(CircularDoubleLink* link) {
        DoubleLink::setNext(link);
        link->lastLink = lastLink;
    }

    void setPrev(CircularDoubleLink* link) {
        DoubleLink::setPrev(link);
        link->lastLink = lastLink;
    }

    // override getLast to return the last link, which is the link before the first link
    CircularDoubleLink& getLast() {
        return *lastLink;
    }

    // override getFirst to return this link, since it's the first link
    CircularDoubleLink& getFirst() {
        return *this;
    }

private:
    CircularDoubleLink* lastLink;
};
