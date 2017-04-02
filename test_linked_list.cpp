#include <iostream>

#include "linked_list.h"

using namespace std;

// Global symbolic constants.
const int NODES = 10;
const string TEST_LABEL = "[ TEST ] ";

// Test method prototypes.
void testLinkedList();

int main() {
    testLinkedList();
    return 0;
}

void testLinkedList() {
    IntLNode *node_p;
    IntLinkedList *list;

    cout << TEST_LABEL << "Testing LinkedList class." << endl;
    list = new IntLinkedList();

    cout << TEST_LABEL << "List before populating:" << endl
        << *list << endl;

    cout << TEST_LABEL << "Populating list..." << endl;

    for (int i = 0; i < NODES; i++) {
        node_p = new IntLNode(i);
        list->push_front(node_p);
    }

    cout << TEST_LABEL << "List after populating:" << endl
        << *list << endl;

    cout << TEST_LABEL << "Popping and displaying from front of list" << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = list->front();
        cout << *node_p << endl;
        list->pop_front();
    }
}

