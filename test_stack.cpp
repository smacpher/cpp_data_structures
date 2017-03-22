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
    IntStack stack_0, stack_1;
    IntStackNode *node_p, *node_0_p, *node_1_p;

    cout << "Populating stack_0 and stack_1..." << endl;

    for (int i = 0; i < NODES; i++) {
        node_0_p = new IntStackNode(i);
        node_1_p = new IntStackNode(i * i);

        stack_0.push(node_0_p);
        stack_1.push(node_1_p);
    }

    cout << "stack_0" << endl;
    cout << stack_0.toString() << endl;

    cout << "stack_1" << endl;
    cout << stack_1.toString() << endl;

    cout << "Deallocating stack_0 nodes with garbageCollect()..." << endl;
    cout << boolalpha << "Garbage collecting stack_0 success? "
        << stack_0.garbageCollect() << endl;

    cout << boolalpha << "stack_0 empty? " << stack_0.isEmpty() << endl;
    cout << stack_0.toString() << endl;

    cout << "Deallocating stack_1 nodes manually with pop() and delete..."
        << endl;

    cout << "Popping elements off of stack_1" << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = stack_1.pop();
        cout << "Popped: " << node_p->toString() << endl;

        delete node_p;
    }

    cout << boolalpha << "stack_1 empty? " << stack_1.isEmpty() << endl;
    cout << stack_1.toString() << endl;
}
