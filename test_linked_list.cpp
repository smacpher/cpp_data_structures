#include <iostream>
#include "linked_list.h"

using namespace std;

// Test method prototypes.
void testLinkedList();

int main() {
    testLinkedList();
    return 0;
}

void testLinkedList() {
    IntLinkedList list;

    list = IntLinkedList();

    cout << list << endl;
}

