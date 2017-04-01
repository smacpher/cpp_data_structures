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

    for (int i = 0; i < NODES; i++) {
        node_p = new IntLNode(i);
        cout << *node_p << endl;
        list->push_front(node_p);
    }

    cout << list << endl;
    // for (int i = 0; i < NODES; i++) {
    //     node_p = list->back();
    //     cout << *node_p << endl;
    // }
}

