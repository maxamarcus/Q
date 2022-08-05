#inlcude "Q.h"

template <class t>
class ArrayQ : public Q <t> {

public:

    // CONSTRUCTOR
    ArrayQ(int);
    ~ArrayQ();

    // TRANSFORMERS
    virtual void EnQ(t);
    virtual t DeQ();
    virtual void MakeEmpty();

    // OBSERVERS
    virtual bool IsEmpty();
    virtual bool IsFull();

protected:

    // MEMBER VARIABLES
    t * array;
    int arrayLength;
    int first;
    int last;

    // HELPER FUNCTIONS
    void DoubleCapacity();

};



template <class t>
ArrayQ <t> :: ArrayQ(int capacity) {
    this->arrayLength = capacity + 1;
    this->array = new t [arrayLength];
    this->first = arrayLength - 1;
    this->last = arrayLength - 1;
}



template <class t>
ArrayQ <t> :: ~ArrayQ() {
    delete [] this->array;
}



template <class t>
void ArrayQ <t> :: EnQ(t addMe) {
    /* Linear iteration if array is full. Otherwise constant time. */
    if (this->IsFull()) {
        this->DoubleCapacity();
    }
    last = (last + 1) % arrayLength;
    this->array[last] = addMe;
}



template <class t>
t ArrayQ <t> :: DeQ() {
    if (this->IsEmpty()) {
        throw EmptyQ();
    }
    first = (first + 1) % arrayLength;
    return array[first];
}



template <class t>
void ArrayQ <t> :: MakeEmpty() {
    last = first;
}



template <class t>
bool ArrayQ <t> :: IsEmpty() {
    return (first == last);
}



template <class t>
bool ArrayQ <t> :: IsFull() {
    return (first == (last + 1) % arrayLength);
}



template <class t>
void ArrayQ <t> :: DoubleCapacity() {
    /* Linear iteration. */
    t * newArray = new t [arrayLength * 2];
    int current = first;
    while (current != last) {
        newArray[current] = array[current];
        current = (current + 1) % arrayLength;
    }
    delete this->array;
    this->array = newArray;
    arrayLength *= 2;
}