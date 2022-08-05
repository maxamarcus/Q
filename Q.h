// Q ABC
/* First-in-first-out queue. */

// EXCEPTIONS
class EmptyQ {};

template <class t>
class Q {
public:

    // TRANSFORMERS
    virtual void EnQ(t) = 0;
    virtual t DeQ() = 0;
    virtual void MakeEmpty() = 0;

    // OBSERVERS
    virtual bool IsEmpty() = 0;
    virtual bool IsFull() = 0;

};