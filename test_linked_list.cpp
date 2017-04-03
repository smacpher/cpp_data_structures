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

    cout << TEST_LABEL << "List before populating." << endl;
    cout << *list << endl;

    cout << TEST_LABEL << "Populating list with push_front()." << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = new IntLNode(i);
        list->push_front(node_p);
    }

    cout << TEST_LABEL << "List after populating." << endl;
    cout << *list << endl;

    cout << TEST_LABEL << "Output of front()." << endl;
    cout << list->front()->to_string() << endl;
    cout << TEST_LABEL << "Output of back()." << endl;
    cout << list->back()->to_string() << endl;
    cout << TEST_LABEL << "Output of size()." << endl;
    cout << list->size() << endl;

    cout << TEST_LABEL << "Displaying list with to_string()." << endl;
    cout << *list << endl; // Overloaded operator '<<' calls to_string().

    cout << TEST_LABEL << "Deleting list." << endl;
    delete list;

    cout << TEST_LABEL << "List after deleting." << endl;
    cout << *list << endl;

    list = new IntLinkedList();
    cout << TEST_LABEL << "List before populating." << endl;
    cout << *list << endl;
    cout << TEST_LABEL << "Populating list with push_back()." << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = new IntLNode(i);
        list->push_back(node_p);
    }

    cout << TEST_LABEL << "List after populating." << endl;
    cout << *list << endl;


    cout << TEST_LABEL << "Output of front()." << endl;
    cout << list->front()->to_string() << endl;
    cout << TEST_LABEL << "Output of back()." << endl;
    cout << list->back()->to_string() << endl;
    cout << TEST_LABEL << "Output of size()." << endl;
    cout << list->size() << endl;

}

