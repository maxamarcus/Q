#include "Q.h"

// DEFINITIONS
template <class t>
struct node {
    t info;
    node * next;
};



template <class t>
class LinkedQ : public Q <t> {

public:

    // CONSTRUCTOR
    LinkedQ();
    ~LinkedQ();

    // TRANSFORMERS
    virtual void EnQ(t);
    virtual t DeQ();
    virtual void MakeEmpty();

    // OBSERVERS
    virtual bool IsEmpty();
    virtual bool IsFull();

private:

    // MEMBER VARIABLES
    node <t> * first;
    node <t> * last;
};



template <class t>
LinkedQ <t> :: LinkedQ() {
    this->first = nullptr;
    this->last = nullptr;
}



template <class t>
LinkedQ <t> :: ~LinkedQ() {
    /* Linear iteration. */
    this->MakeEmpty();
}



template <class t>
void LinkedQ <t> :: EnQ(t addMe) {

    // Create node:
    node <t> * toAdd = new node <t>;
    toAdd->info = addMe;
    toAdd->next = nullptr;

    // Special case -- Q is empty:
    if (this->IsEmpty()) {
        this->first = toAdd;
        this->last = toAdd;
    }

    // Common case -- Q is not empty:
    else {
        this->last->next = toAdd;
        this->last = toAdd;
    }
}



template <class t>
t LinkedQ <t> :: DeQ() {

    if (this->IsEmpty()) {
        throw EmptyQ();
    }

    else {
        t toReturn = this->first->info;
        node <t> * newFirst = this->first->next;
        delete this->first;
        this->first = newFirst;
        return toReturn;
    }
}



template <class t>
void LinkedQ <t> :: MakeEmpty() {
    /* Linear iteration. */
    node <t> * ptr = this->first;
    while (this->first != nullptr) {
        this->first = this->first->next;
        delete ptr;
        ptr = this->first;
    }
}



template <class t>
bool LinkedQ <t> :: IsEmpty() {
    return this->first == nullptr;
}



template <class t>
bool Linked Q <t> :: IsFull() {
    return false;
}