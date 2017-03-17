#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

/* Forward declaration(s). */
template <class T>
class Stack;

/* StackNode prototype. */
template <class T>;
class StackNode<T> {
    friend Stack;

    public:
        // Static symbolic constants.
        static const string STACK_NODE_LABEL;

    protected:
        StackNode<T> *next;
        T data;

    public:
        // Constructor(s) / destructor.
        StackNode();
        StackNode(T data);
        virtual ~StackNode();
 
        // Public instance methods.
        string toString() const;

    // Overloaded non-member friend operator(s).
    friend ostream& operator<<(ostream &os, const StackNode &node);
};

/* Stack prototype. */
template <class T>
class Stack<T> {
    protected:
        StackNode *top;
        int size;

    public:
        // Constructor(s) / destructor.
        Stack();
        virtual ~Stack();

        // Public instance methods.
        bool push(StackNode *node);
        bool push(T data);

        StackNode* pop();
        int isEmpty() const;
};

/* StackNode definition. */
// Constructor / destructor.
template <class T>
StackNode<T>::StackNode() {
    this->next = NULL;
    this->data = T();
}

template <class T>
StackNode<T>::StackNode(T data) {
    this->next = NULL;
    this->data = data;
}

template <class T>
StackNode<T>::~StackNode() {
}

// Misc. other public instance methods.
template <class T>
StackNode<T>::toString() const {
    ostringstream os;
    os << StackNode::STACK_NODE_LABEL << " [ " << this->data << " ] ";
    return os.str();
}

// Overloaded non-member friend operator(s).
ostream& operator<<(ostream &os, const StackNode &node) {
    os << node.toString();
    return os;
}

/* Stack definition. */

#endif /* STACK_H */

