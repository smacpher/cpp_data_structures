#include <iostream>

#include "linked_list.h"
#include "utils.h"

using namespace std;

// Global symbolic constants.
const int NODES = 10;
const string TEST_LABEL = "[ TEST ] ";

// Test method prototypes.
void testLinkedList();
void testDoublyLinkedList();

// Main client.
int main() {
    testLinkedList();
    testDoublyLinkedList();
    return 0;
}

// Test method definition(s).
void testLinkedList() {
    int rand_i;
    IntLNode *node_p;
    IntLinkedList *list;
    Utils utils;

    // Instantiate utils class.
    utils = Utils();

    // LinkedList tests.
    cout << TEST_LABEL << "Testing LinkedList class." << endl;
    list = new IntLinkedList();

    cout << TEST_LABEL << "List before populating." << endl;
    cout << *list << endl;
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Populating list with push_front()." << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = new IntLNode(i);
        list->push_front(node_p);
    }

    cout << TEST_LABEL << "List after populating." << endl;
    cout << *list << endl;
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Output of front()." << endl;
    cout << list->front()->to_string() << endl;
    cout << TEST_LABEL << "Output of back()." << endl;
    cout << list->back()->to_string() << endl;
    cout << TEST_LABEL << "Output of size()." << endl;
    cout << list->size() << endl;

    cout << TEST_LABEL << "Displaying list with to_string()." << endl;
    cout << *list << endl; // Overloaded operator '<<' calls to_string().
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Deleting list." << endl;
    delete list;

    cout << TEST_LABEL << "List after deleting." << endl;
    cout << *list << endl;

    list = new IntLinkedList();
    cout << TEST_LABEL << "List before populating." << endl;
    cout << *list << endl;
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Populating list of squares with push_back()."
        << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = new IntLNode(i * i);
        list->push_back(node_p);
    }

    cout << TEST_LABEL << "List after populating with squares." << endl;
    cout << *list << endl;
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Output of front()." << endl;
    cout << list->front()->to_string() << endl;
    cout << TEST_LABEL << "Output of back()." << endl;
    cout << list->back()->to_string() << endl;
    cout << TEST_LABEL << "Output of size()." << endl;
    cout << list->size() << endl;

    cout << TEST_LABEL << "Testing at() with random index." << endl;
    for (int i = 0; i < NODES; i++) {
        rand_i = utils.rand_int_between(0, NODES - 1);
        cout << "Node at index " << rand_i << ": "
            << list->at(rand_i)->to_string() << endl;
    }
}

void testDoublyLinkedList() {
    int rand_i;
    IntDLNode *node_p;
    IntDoublyLinkedList *list;
    Utils utils;

    // Instantiate utils class.
    utils = Utils();

    // DoublyLinkedList tests.
    cout << TEST_LABEL << "Testing DoublyLinkedList class." << endl;
    list = new IntDoublyLinkedList();

    cout << TEST_LABEL << "List before populating." << endl;
    cout << *list << endl;
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Populating list with push_front()." << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = new IntDLNode(i);
        list->push_front(node_p);
    }

    cout << TEST_LABEL << "List after populating." << endl;
    cout << *list << endl;
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Output of front()." << endl;
    cout << list->front()->to_string() << endl;
    cout << TEST_LABEL << "Output of back()." << endl;
    cout << list->back()->to_string() << endl;
    cout << TEST_LABEL << "Output of size()." << endl;
    cout << list->size() << endl;

    cout << TEST_LABEL << "Displaying list with to_string()." << endl;
    cout << *list << endl; // Overloaded operator '<<' calls to_string().
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Deleting list." << endl;
    delete list;

    cout << TEST_LABEL << "List after deleting." << endl;
    cout << *list << endl;

    list = new IntDoublyLinkedList();
    cout << TEST_LABEL << "List before populating." << endl;
    cout << *list << endl;
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Populating list of squares with push_back()."
        << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = new IntDLNode(i * i);
        list->push_back(node_p);
    }

    cout << TEST_LABEL << "List after populating with squares." << endl;
    cout << *list << endl;
    cout << TEST_LABEL << "Prettify'd list." << endl;
    cout << list->prettify() << endl;

    cout << TEST_LABEL << "Output of front()." << endl;
    cout << list->front()->to_string() << endl;
    cout << TEST_LABEL << "Output of back()." << endl;
    cout << list->back()->to_string() << endl;
    cout << TEST_LABEL << "Output of size()." << endl;
    cout << list->size() << endl;

    cout << TEST_LABEL << "Testing at() with random index." << endl;
    for (int i = 0; i < NODES; i++) {
        rand_i = utils.rand_int_between(0, NODES - 1);
        cout << "Node at index " << rand_i << ": "
            << list->at(rand_i)->to_string() << endl;
    }

    delete list;

}
