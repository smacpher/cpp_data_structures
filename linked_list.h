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
        bool push_front(LNode<T> *node);
        bool push_back(LNode<T> *node);
        LNode<T> *node front();
        LNode<T> *node back();

        string to_string() const;
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

    if (l_list->head != NULL) {

        // Initialize pointers.
        other_node_p = l_list->head;
        this_node_p = NULL;

        // Copy and instantiate head.
        this->head = NULL;
        this->head = new LNode(*other_node_p);
        this_node_p; = this->head;

        while (other_node_p->next != NULL) {
            this_node_p->next = new LNode(*other_node_p->next);

            // Increment pointers.
            this_node_p = this_node_p->next;
            other_node_p = other_node_p->next;
        }
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    LNode<T> *node_p;

    node_p = this->head;
    while ((node_p = node_p->next != NULL))
        delete node_p;

    this->head = NULL;
}

template <class T>
bool LinkedList<T>::push_front(LNode<T> *node) {
    if (node == NULL)
        return false;

    node_p->next = this->head;
    this->head = node_p;
    return true;
}

/* DoublyLinkedList class prototype. */

/* Out-of-line definitions. */
const string LinkedList<T>::FRONT_LABEL = " [ Front of LinkedList ] ";
const string LinkedList<T>::BACK_LABEL = " [ Back of LinkedList ] ";
const string DoublyLinkedList<T>::FRONT_LABEL = " [ Front of DoublyLinkedList ] ";
const string DoublyLinkedList<T>::BACK_LABEL = " [ Back of DoublyLinkedList ] ";

#endif /* LINKED_LIST_H */
