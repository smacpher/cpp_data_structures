#ifndef QUEUE_H
#define QUEUE_U

#include <sstream>
#include <string>

#include "base.h"
#include "linked_list.h"

using namespace std;

/* Queue prototype. */
template <class T>
class Queue {
    public:
        // Static symbolic constants.
        static const string FRONT_LABEL;
        static const string BACK_LABEL;
        static const string PRETTIFY_DELIMETER;

    private:
        DoublyLinkedList<T> *queue;

    public:
        // Constructor(s) / destructor.
        Queue();
        Queue(const Queue<T> &queue);

        ~Queue();

        // Public instance method(s).
        bool enqueue(LNode<T> *new_node_p);
        bool enqueue(T data);
        LNode<T> *node dequeue();

        string to_string() const;
        string prettify() const;

    // Overloaded non-member friend operator(s).
    friend ostream& operator<<(ostream &os, const Queue<T> &queue) {
        os << queue.to_string();
        return os;
    }

};

/* Dequeue prototype. */
// template <class T>
// class Dequeue {

// };

#endif /* QUEUE_H */

/* Queue definition. */
template <class T>
Queue<T>::Queue() {
    this->queue = new DoublyLinkedList();
}

template <class T>
Queue<T>::Queue(const Queue<T> &queue) {

}

template <class T>
Queue<T>::~Queue() {
    delete this->queue;
}

template <class T>
bool Queue<T>::enqueue(LNode<T> *new_node_p) {
    this->queue->push_front(new_node_p);
}

template <class T>
bool Queue<T>::enqueue(T data) {
    LNode<T> *new_node_p;
    new_node_p = new LNode<T>(data);
    this->queue->push_front(new_node_p);
}

template <class T>
bool Queue<T>::dequeue() {
    this->queue->pop_back(node);
}

template <class T>
string Queue<T>::to_string() const {
    LNode<T> *node_p;

    ostringstream os;

    os << Queue<T>::FRONT_LABEL << endl;

    for (node_p = this->queue->head; node_p != NULL; node_p = node_p->next)
        os << node_p->to_string() << endl;

    os << Queue<T>::BACK_LABEL << endl;

    return os.str();
}

template <class T>
string Queue<T>::prettify() const {
    LNode<T> *node_p;

    ostringstream os;

    os << Queue<T>::FRONT_LABEL;

    for (node_p = this->queue->head; node_p != NULL; node_p = node_p->next)
        os << node_p->to_string() << Queue<T>::PRETTIFY_DELIMETER;

    os << Queue<T>::BACK_LABEL << endl;

    return os.str();
}

/* Dequeue definition. */

/* Out-of-line definitions. */
template <class T>
const string Queue<T>::FRONT_LABEL = " [ Front of Queue ] ";
template <class T>
const string Queue<T>::BACK_LABEL = " [ Back of Queue ] ";
template <class T>
const string Queue<T>::PRETTIFY_DELIMETER = " -- ";

/* Typedef forward declarations. */
typedef Queue<int> IntQueue;
typedef Queue<float> FloatQueue;
typedef Queue<double> DoubleQueue;
typedef Queue<char> CharQueue;
typedef Queue<string> StringQueue;
