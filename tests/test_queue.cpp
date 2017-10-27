#include <iostream>
#include "catch.hpp"
#include "../queue.h"

using namespace std;

/* Global symbolic constants. */
const int NUM_TEST_NODES = 10;
const string TEST_LABEL = " [ TEST ] ";

/* Catch unit test(s). */

TEST_CASE("Testing Queue", "[Queue]") {
    /* Instantiate Queue. */
    IntDLNode *node_p;
    IntQueue *queue;

    queue = new IntQueue;

    SECTION("Queue::size") {
        REQUIRE(queue->size() == 0);
    }

    SECTION("Queue::empty") {
        REQUIRE(queue->empty() == true);
    }

    SECTION("Queue::enqueue") {
        for (int i = 0; i < NUM_TEST_NODES; i++) {
            node_p = new IntDLNode(i);
            queue->enqueue(node_p);
        }
        
        REQUIRE(queue->size() == NUM_TEST_NODES);
        REQUIRE(queue->empty() == false);
    }
    
    /* Clean up. */
    delete queue;
}

