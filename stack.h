#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/* Forward declaration(s). */
template <class T>
class Stack;

/* StackNode prototype. */
template <class T>
class StackNode {
    template <class W>
    friend class Stack;

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
        StackNode(const StackNode<T> &node);

        virtual ~StackNode();
 
        // Public instance methods.
        string toString() const;

    // Overloaded non-member friend operator(s).
    friend ostream& operator<<(ostream &os, const StackNode<T> &node);
};

/* Stack prototype. */
template <class T>
class Stack {
    public:
        // Static symbolic constants.
        static const string STACK_LABEL;
        static const string END_STACK_LABEL;

    protected:
        StackNode<T> *top;
        int size;

    public:
        // Constructor(s) / destructor.
        Stack();
        virtual ~Stack();

        // Public instance methods.
        bool push(StackNode<T> *node);
        bool push(T data);
        StackNode<T>* pop();
        bool isEmpty() const;
        string toString() const;
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
StackNode<T>::StackNode(const StackNode<T> &node) {
    this->next = NULL;
    this->data = node.data;
}

template <class T>
StackNode<T>::~StackNode() {
}

// Misc. other public instance methods.
template <class T>
string StackNode<T>::toString() const {
    ostringstream os;
    os << StackNode<T>::STACK_NODE_LABEL << " [ " << this->data << " ] ";
    return os.str();
}

// Overloaded non-member friend operator(s).
template <class T>
ostream& operator<<(ostream &os, const StackNode<T> &node) {
    os << node.toString();
    return os;
}

/* Stack definition. */
// Constructor(s) / destructor.
template <class T>
Stack<T>::Stack() {
    this->size = 0;
    this->top = NULL;
}

template <class T>
Stack<T>::~Stack() {
}

template <class T>
bool Stack<T>::push(StackNode<T>* node) {
    node->next = this->top;
    this->top = node;

    return true;
}

template <class T>
bool Stack<T>::push(T data) {
    StackNode<T>* node_p;

    // Instantiate StackNode<T>.
    node_p = new StackNode<T>();

    // Assign data and next.
    node_p->data = data;
    node_p->next = this->top;

    // Update top.
    this->top = node_p;

    size++;

    return true;
}

template <class T>
StackNode<T>* Stack<T>::pop() {
    this->size--;
 
    StackNode<T>* popped = this->top;
    this->top = this->top->next;

    return popped;
}

template <class T>
bool Stack<T>::isEmpty() const {
    return this->size == 0;
}

template <class T>
string Stack<T>::toString() const {
    StackNode<T>* stack_node_p;

    cout << Stack<T>::STACK_LABEL << endl;

    for (stack_node_p = this->top; stack_node_p != NULL; stack_node_p->next) {
        cout << stack_node_p->toString() << endl;
    }

    cout << Stack<T>::END_STACK_LABEL << endl;
}

template <class T>
const string StackNode<T>::STACK_NODE_LABEL = "[ StackNode ]";
template <class T>
const string Stack<T>::STACK_LABEL = " Stack ";
template <class T>
const string Stack<T>::END_STACK_LABEL = " End Stack ";

/* Typedef forward declaration(s). */
typedef StackNode<int> IntStackNode;
typedef StackNode<float> FloatStackNode;
typedef StackNode<double> DoubleStackNode;
typedef StackNode<char> CharStackNode;
typedef StackNode<string> StringStackNode;

#endif /* STACK_H */

