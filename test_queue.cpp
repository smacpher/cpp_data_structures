#include <iostream>

#include "queue.h"

using namespace std;

// Test method prototype(s).
void testQueue();

// Main client.
int main() {
    testQueue();
    return 0;
}
// Test method definition(s).
void testQueue() {
    IntQueue *queue;

    queue = new Queue();

    queue->enqueue();
}

