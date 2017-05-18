#include <string>
#include "catch.hpp"
#include "../stack.h"

using namespace std;

// Global symbolic constants.
const int TEST_VALUE = 21;
const string EXPECTED_LNODE_TOSTRING = "[ LNode (Linked Node) ] [ 21 ]";
const string EXPECTED_DLNODE_TOSTRING = "[ DLNode (Doubly-linked Node) ] [ 21 ]";
const int NUM_TEST_NODES = 10;
const string TEST_LABEL = "[ TEST ] ";

/* CATCH unit tests. */
TEST_CASE("Testing LNode (Linked Node class)", "[LNode]") {

    IntLNode* l_node;

    l_node = new IntLNode(TEST_VALUE);

    SECTION("Print LNode to cout") {
        cout << *l_node << endl;
    }

    SECTION("LNode::to_string()") {
        REQUIRE(l_node->to_string() == EXPECTED_LNODE_TOSTRING);
    }

    /* Clean up. */
    delete l_node;
}

TEST_CASE("Testing DLNode (Doubly-linked Node class)", "[DLNode]") {
    IntDLNode* dl_node;

    dl_node = new IntDLNode(TEST_VALUE);

    SECTION("Print DLNode to cout") {
        cout << *dl_node << endl;
    }

    SECTION("DLNode::to_string()") {
        REQUIRE(dl_node->to_string() == EXPECTED_DLNODE_TOSTRING);
    }

    /* Clean up. */
    delete dl_node;
}

TEST_CASE("Testing stack", "[Stack]") {
    IntStack stack_0, stack_1;
    IntLNode *node_p, *node_0_p, *node_1_p;

    /* Populate stacks. */

    for (int i = 0; i < NUM_TEST_NODES; i++) {
        node_0_p = new IntLNode(i);
        node_1_p = new IntLNode(i * i);

        stack_0.push(node_0_p);
        stack_1.push(node_1_p);
    }

    SECTION("Print stacks to cout") {
        cout << "stack_0" << endl;
        cout << stack_0 << endl;

        cout << "stack_1" << endl;
        cout << stack_1 << endl;
    }

    SECTION("Deallocate stack_0 with garbage_collect()") {
        REQUIRE(stack_0.garbage_collect() == true);
        REQUIRE(stack_0.empty() == true);
    }

    SECTION("Deallocate stack_1 with pop() and delete") {
        for (int i = 0; i < NUM_TEST_NODES; i++) {
            node_p = stack_1.pop();

            delete node_p;
        }

        REQUIRE(stack_1.empty() == true);
    }
}
