#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <string>

#include "base.h"

using namespace std;

/* Stack prototype. */
template <class T>
class Stack {
    public:
        // Static symbolic constants.
        static const string TOP_LABEL;
        static const string END_LABEL;

    protected:
        // Protected members.
        LNode<T> *top;

    public:
        // Constructor(s) / destructor.
        Stack();
        virtual ~Stack();

        // Public instance methods.
        bool push(LNode<T> *node);
        bool push(T data);
        LNode<T>* pop();
        bool is_empty() const;
        string to_string() const;
        bool garbage_collect();

    // Overloaded non-member friend operator(s).
    friend ostream& operator<<(ostream &os, const Stack<T> &stack) {
        os << stack.to_string();
        return os;
    }
};

#endif /* STACK_H */

/* Stack definition. */
// Constructor(s) / destructor.
template <class T>
Stack<T>::Stack() {
    this->top = NULL;
}

template <class T>
Stack<T>::~Stack() {
}

template <class T>
bool Stack<T>::push(LNode<T>* node) {
    if (node == NULL)
        return false;

    node->next = this->top;
    this->top = node;

    return true;
}

template <class T>
bool Stack<T>::push(T data) {
    LNode<T>* node_p;

    // Instantiate LNode<T>.
    node_p = new LNode<T>();

    // Assign data and next.
    node_p->data = data;
    node_p->next = this->top;

    // Update top.
    this->top = node_p;

    return true;
}

template <class T>
LNode<T>* Stack<T>::pop() {
    LNode<T>* popped;

    popped = this->top;
    this->top = this->top->next;

    return popped;
}

template <class T>
bool Stack<T>::is_empty() const {
    return this->top == NULL;
}

template <class T>
string Stack<T>::to_string() const {
    ostringstream os;
    LNode<T>* stack_node_p;

    os << Stack<T>::TOP_LABEL << endl;

    if (this->top != NULL) {
        for (stack_node_p = this->top;
             stack_node_p != NULL;
             stack_node_p = stack_node_p->next) {

            os << stack_node_p->to_string() << endl;
        }
    }

    os << Stack<T>::END_LABEL;
    return os.str();
}

template <class T>
bool Stack<T>::garbage_collect() {
    LNode<T>* stack_node_p;

    for (stack_node_p = this->top;
         stack_node_p != NULL;
         stack_node_p = stack_node_p->next) {

        delete stack_node_p;
    }

    this->top = NULL;
    return true;
}

// Out-of-line definitions.
template <class T>
const string Stack<T>::TOP_LABEL = "[[ Top of Stack ]]";
template <class T>
const string Stack<T>::END_LABEL = "[[ Bottom of Stack ]]";

/* Typedef forward declarations. */
typedef Stack<int> IntStack;
typedef Stack<float> FloatStack;
typedef Stack<double> DoubleStack;
typedef Stack<char> CharStack;
typedef Stack<string> StringStack;
