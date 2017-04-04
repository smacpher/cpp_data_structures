#ifndef BASE_H
#define BASE_H

#include <sstream>
#include <string>

using namespace std;

/* Forward declaration(s). */
template <class T> class Stack;
template <class T> class LinkedList;
template <class T> class DoublyLinkedList;
template <class T> class Queue;
template <class T> class Dequeue;

/* LNode -- 'Linked Node' -- prototype. */
template <class T>
class LNode {

    template <class W> friend class Stack;
    template <class W> friend class LinkedList;

    public:
        // Static symbolic constants.
        static const string LABEL;

    private:
        LNode<T> *next;
        T data;

    public:
        // Constructor(s) / destructor.
        LNode();
        LNode(T data);
        LNode(const LNode<T> &node);

        virtual ~LNode();
 
        // Public instance methods.
        virtual string to_string() const;

    // Overloaded non-member friend operator(s).
    friend ostream& operator<<(ostream &os, const LNode<T> &node) {
        os << node.to_string();
        return os;
    }
};

/* DLNode -- 'Doubly-linked Node' -- prototype. */
template <class T>
class DLNode : public LNode<T> {

    template <class W> friend class DoublyLinkedList;

    public:
        // Static symbolic constants.
        static const string LABEL;

    private:
        DLNode<T> *next;
        DLNode<T> *prev;
        T data;

    public:
        // Constructor(s) / destructor.
        DLNode();
        DLNode(T data);
        DLNode(const DLNode<T> &node);

        virtual ~DLNode();

        // Public instance methods.
        virtual string to_string() const;
};

/* Wrapper classes to add clarity to users. */
/* QNode -- 'Queue Node' -- prototype. */
template <class T>
class QNode : public LNode<T> {

    template <class W> friend class Queue;

    public:
        // Static symbolic constants.
        static const string LABEL;

};

/* DQNode -- 'Dequeue Node' -- prototype. */
template <class T>
class DQNode : public DLNode<T> {

    template <class W> friend class Dequeue;

    public:
        // Static symbolic constants.
        static const string LABEL;
};

#endif /* BASE_H */

/* LNode definition. */
template <class T>
LNode<T>::LNode() {
    this->next = NULL;
    this->data = T();
}

template <class T>
LNode<T>::LNode(T data) {
    this->next = NULL;
    this->data = data;
}

template <class T>
LNode<T>::LNode(const LNode<T> &node) {
    this->next = NULL;
    this->data = node.data;
}

template <class T>
LNode<T>::~LNode() {
}

template <class T>
string LNode<T>::to_string() const {
    ostringstream os;
    os << LNode<T>::LABEL << " [ " << this->data << " ] ";
    return os.str();
}

/* DLNode -- 'Doubly-linked Node' -- prototype. */
template <class T>
DLNode<T>::DLNode() {
    this->next = NULL;
    this->prev = NULL;
    this->data = T();
}

template <class T>
DLNode<T>::DLNode(T data) {
    this->next = NULL;
    this->data = data;
}

template <class T>
DLNode<T>::DLNode(const DLNode<T> &node) {
    this->next = NULL;
    this->prev = NULL;
    this->data = node.data;
}

template <class T>
DLNode<T>::~DLNode() {
}

template <class T>
string DLNode<T>::to_string() const {
    ostringstream os;
    os << DLNode<T>::LABEL << " [ " << this->data << " ] ";
    return os.str();
}

/* Out-of-line declarations. */
template <class T>
const string LNode<T>::LABEL = "[ LNode (Linked Node) ]";
template <class T>
const string DLNode<T>::LABEL = "[ DLNode (Doubly-linked Node) ]";

/* Typdef forward declarations. */
typedef LNode<int> IntLNode;
typedef LNode<float> FloatLNode;
typedef LNode<double> DoubleLNode;
typedef LNode<char> CharLNode;
typedef LNode<string> StringLNode;

typedef DLNode<int> IntDLNode;
typedef DLNode<float> FloatDLNode;
typedef DLNode<double> DoubleDLNode;
typedef DLNode<char> CharDLNode;
typedef DLNode<string> StringDLNode;
