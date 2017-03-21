#include "stack.h"

using namespace std;

// Global symbolic constants.
const int NODES = 10;

// Test method declarations.
void testStackNode();
void testStack();


// Main client.
int main() {
    // testStackNode();
    testStack();

    return 0;
}

// Test method definitions.
void testStackNode() {
    IntStackNode* stack_node;

    stack_node = new IntStackNode(17);

    cout << *stack_node << endl;

    delete stack_node;
}

void testStack() {
    IntStack stack;
    IntStackNode* node_p;

    for (int i = 0; i < NODES; i++) {
        node_p = new IntStackNode(i);
        stack.push(node_p);
    }

    cout << stack.toString() << endl;

    stack.garbageCollect();
}

