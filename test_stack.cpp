#include "stack.h"

using namespace std;

// Test method declarations.
void testStackNode();

// Main client.
int main() {
    testStackNode();

    return 0;
}

// Test method definitions.
void testStackNode() {
    IntStackNode* stack_node;

    stack_node = new IntStackNode();

    delete stack_node;
}

