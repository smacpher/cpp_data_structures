#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <sstream>
#include <string>

#include "base.h"

/* LinkedList class prototype. */
template <class T>
class LinkedList {

    public:
        // Static symbolic constants.
        static const string FRONT_LABEL;
        static const string BACK_LABEL;

    protected:
        // Protected members.
        LNode<T> *head;

    public:
        // Constructor(s) / destructor.
        LinkedList();
        LinkedList(const LinkedList<T> &l_list);

        virtual ~LinkedList();

        // Public instance methods.
        bool push_front(LNode<T> *new_node_p);
        bool push_front(T data);
        bool push_back(LNode<T> *new_node_p);
        bool push_back(T data);

        void pop_front();
        void pop_back();

        LNode<T>* front() const;
        LNode<T>* back() const;

        int size() const;

        string to_string() const;

        // Recurisve helpers.
        bool push_back(LNode<T> *new_node_p, LNode<T> *node_p); // Recursive helper.
        void pop_back(LNode<T> *node); // Recursive helper. 
        LNode<T>* back(LNode<T> *node_p) const; // Recursive helper.
        int size(LNode<T> *node_p, int size = 0) const;

    // Overloaded non-member friend operator(s).
    friend ostream& operator<<(ostream &os, const LinkedList<T> &list) {
        os << list.to_string();
        return os;
    }
};

/* DoublyLinkedList class prototype. */
template <class T>
class DoublyLinkedList {

    public:
        // Static symbolic constants.
        static const string FRONT_LABEL;
        static const string BACK_LABEL;
};

/* LinkedList class definition. */
template <class T>
LinkedList<T>::LinkedList() {
    this->head = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList &l_list) {
    LNode<T> *other_node_p, *this_node_p;

    if (l_list->head == NULL)
        return;

    // Initialize pointers.
    other_node_p = l_list->head;
    this_node_p = NULL;

    // Copy and instantiate head.
    this->head = NULL;
    this->head = new LNode<T>(*other_node_p);
    this_node_p = this->head;

    while (other_node_p->next != NULL) {
        this_node_p->next = new LNode<T>(*other_node_p->next);

        // Increment pointers.
        this_node_p = this_node_p->next;
        other_node_p = other_node_p->next;
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    LNode<T> *node_p;

    if (this->head == NULL)
        return;

    node_p = this->head;
    while ((node_p = node_p->next) != NULL) {
        delete node_p;
    }

    this->head = NULL;
}

template <class T>
bool LinkedList<T>::push_front(LNode<T> *new_node_p) {
    if (new_node_p == NULL)
        return false;

    new_node_p->next = this->head;
    this->head = new_node_p;
    return true;
}

template <class T>
bool LinkedList<T>::push_front(T data) {
    LNode<T> *new_node_p;

    // Dynamically allocate LNode using param data.
    new_node_p = new LNode<T>(data);
    new_node_p->next = this->head;
    this->head = new_node_p;
    return true;
}

template <class T>
bool LinkedList<T>::push_back(LNode<T> *new_node_p) {
    return this->push_back(new_node_p, this->head);
}

template <class T>
bool LinkedList<T>::push_back(LNode<T> *new_node_p, LNode<T> *node_p) {

    // Protect against NULL passed in nodes.
    if (new_node_p == NULL) {
        return false;
    // Empty list; new_node_p will be the first element.
    } else if (this->head == NULL) { 
        this->head = new_node_p;
        new_node_p->next = NULL;
        return true;
    // Found last node in the list.
    } else if (node_p->next == NULL) {
        node_p->next = new_node_p;
        new_node_p->next = NULL;
        return true;
    // Recursive case.
    } else {
        return this->push_back(new_node_p, node_p->next);
    }
}

template <class T>
bool LinkedList<T>::push_back(T data) {
    LNode<T> *new_node_p;

    // Instantiate new node.
    new_node_p = new LNode<T>(data);

    return this->push_back(new_node_p, this->head);
}

template <class T>
void LinkedList<T>::pop_front() {

    if (this->head == NULL)
        return;

    LNode<T> *temp_p;
    temp_p = this->head;
    this->head = this->head->next;
    delete temp_p;
}

template <class T>
void LinkedList<T>::pop_back() {
    return this->pop_back(this->head);
}

template <class T>
void LinkedList<T>::pop_back(LNode<T> *node_p) {
    if (this->head == NULL) {
        return;
    } else if (node_p->next == NULL) {
        delete node_p;
        return;
    }

    pop_back(node_p->next);
}

template <class T>
LNode<T>* LinkedList<T>::front() const {
    return this->head;
}

template <class T>
LNode<T>* LinkedList<T>::back() const {
    return this->back(this->head);
}

template <class T>
LNode<T>* LinkedList<T>::back(LNode<T> *node_p) const {
    if (node_p->next == NULL)
        return node_p;
    return back(node_p->next);
}

template <class T>
int LinkedList<T>::size() const {
    return this->size(this->head, 0);
}

template <class T>
int LinkedList<T>::size(LNode<T> *node_p, int size) const {
    if (this->head == NULL) {
        return 0;
    } else if (node_p->next == NULL) {
        return size;
    }
    return this->size(node_p->next, ++size);
}

template <class T>
string LinkedList<T>::to_string() const {
    ostringstream os;
    LNode<T>* node_p;

    os << LinkedList<T>::FRONT_LABEL << endl;

    if (this->head != NULL) {
        for (node_p = this->head;
             node_p != NULL;
             node_p = node_p->next) {

            os << node_p->to_string() << endl;
        }
    }

    os << LinkedList<T>::BACK_LABEL;
    return os.str();
}

/* DoublyLinkedList class prototype. */

/* Out-of-line definitions. */
template <class T>
const string LinkedList<T>::FRONT_LABEL = " [ Front of LinkedList ] ";
template <class T>
const string LinkedList<T>::BACK_LABEL = " [ Back of LinkedList ] ";
template <class T>
const string DoublyLinkedList<T>::FRONT_LABEL = " [ Front of DoublyLinkedList ] ";
template <class T>
const string DoublyLinkedList<T>::BACK_LABEL = " [ Back of DoublyLinkedList ] ";

/* Forward declarations. */
typedef LinkedList<int> IntLinkedList;
typedef LinkedList<float> FloatLinkedList;
typedef LinkedList<double> DoubleLinkedList;
typedef LinkedList<char> CharLinkedList;
typedef LinkedList<string> StringLinkedList;

typedef DoublyLinkedList<int> IntDoublyLinkedList;
typedef DoublyLinkedList<float> FloatDoublyLinkedList;
typedef DoublyLinkedList<double> DoubleDoublyLinkedList;
typedef DoublyLinkedList<char> CharDoublyLinkedList;
typedef DoublyLinkedList<string> StringDoublyLinkedList;

#endif /* LINKED_LIST_H */
