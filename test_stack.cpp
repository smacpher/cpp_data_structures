#include <string>

#include "stack.h"

using namespace std;

// Global symbolic constants.
const int NODES = 10;
const string TEST_LABEL = "[ TEST ] ";

// Test method declarations.
void testLNode();
void testDLNode();
void testStack();

// Main client.
int main() {
    testLNode();
    testDLNode();
    testStack();
    return 0;
}

// Test method definitions.
void testLNode() {
    cout << TEST_LABEL << "Testing LNode (Linked Node) class." << endl;

    IntLNode* l_node;
    l_node = new IntLNode(21);

    cout << *l_node << endl;

    delete l_node;
}

// Test method definitions.
void testDLNode() {
    cout << TEST_LABEL << "Testing DLNode (Doubly-linked Node) class." << endl;

    IntDLNode* dl_node;
    dl_node = new IntDLNode(21);

    cout << *dl_node << endl;

    delete dl_node;
}

void testStack() {
    IntStack stack_0, stack_1;
    IntLNode *node_p, *node_0_p, *node_1_p;

    cout << TEST_LABEL << "Testing Stack class." << endl;
    cout << "Populating stack_0 and stack_1..." << endl;

    for (int i = 0; i < NODES; i++) {
        node_0_p = new IntLNode(i);
        node_1_p = new IntLNode(i * i);

        stack_0.push(node_0_p);
        stack_1.push(node_1_p);
    }

    cout << "stack_0" << endl;
    cout << stack_0 << endl;

    cout << "stack_1" << endl;
    cout << stack_1 << endl;

    cout << "Deallocating stack_0 nodes with garbage_collect()..." << endl;
    cout << boolalpha << "Garbage collecting stack_0 success? "
        << stack_0.garbage_collect() << endl;

    cout << boolalpha << "stack_0 empty? " << stack_0.is_empty() << endl;
    cout << stack_0 << endl;

    cout << "Deallocating stack_1 nodes manually with pop() and delete..."
        << endl;

    cout << "Popping elements off of stack_1" << endl;
    for (int i = 0; i < NODES; i++) {
        node_p = stack_1.pop();
        cout << "Popped: " << node_p->to_string() << endl;

        delete node_p;
    }

    cout << boolalpha << "stack_1 empty? " << stack_1.is_empty() << endl;
    cout << stack_1 << endl;
}
