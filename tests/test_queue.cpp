#include <iostream>

#include "queue.h"

using namespace std;

// Global symbolic constants.
const int NODES = 10;
const string TEST_LABEL = " [ TEST ] "

// Test method prototype(s).
void testQueue();

// Main client.
int main() {
    testQueue();
    return 0;
}

// Test method definition(s).
void testQueue() {
    IntDLNode *node_p;
    IntQueue *queue;

    cout << TEST_LABEL << "Testing Queue class." << endl;
    queue = new IntQueue();
    cout << TEST_LABEL << "Queue before populating." << endl;
    cout << *queue << endl;

    cout << TEST_LABEL << "Populating queue with enqueue()." << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = new IntDLNode(i);
        queue->enqueue(node_p);
    }

    cout << TEST_LABEL << "Queue after populating." << endl;
    cout << *queue << endl;
    delete queue;
}

