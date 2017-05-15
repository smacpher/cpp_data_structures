#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/* Forward class declaration(s). */
template <typename T> class BinarySearchTree;

/* BinaryNode class prototype. */
template <typename T>
class BinaryNode {
    protected:
        T element;
        BinaryNode<T> *left;
        BinaryNode<T> *right;

    public:
        /* Constructor(s) / destructor. */
        explicit BinaryNode(T elem = T(),
                            BinaryNode<T> *left_child = nullptr,
                            BinaryNode<T> *right_child = nullptr);
        
        ~BinaryNode();

        /* Public instance method(s). */
        string toString() const;
    
    /* Friend class declaration(s). */
    friend class BinarySearchTree<T>;

    /* Operator overload(s). */
    friend ostream& operator<<(ostream &os, const BinaryNode<T> &node) {
        os << node.toString();
    }
};

/* BinaryNode class definition. */
/* Constructor(s) / destructor. */
template <typename T>
BinaryNode<T>::BinaryNode(T elem, BinaryNode<T> *left_child, 
                          BinaryNode<T> *right_child)
    : element{ elem }, left { left_child }, right { right_child } {
}

template <typename T>
BinaryNode<T>::~BinaryNode() {
    // Recursive destructor.
    delete left;
    delete right;
}

/* Public instance method(s). */ 
template <typename T>
string BinaryNode<T>::toString() const {
    ostringstream os;
    os << "( " << element << " ) ";
    return os.str();
}

/* BinarySearchTree class prototype. */
template <typename T>
class BinarySearchTree {
    private:
        BinaryNode<T> *root;

    private:
        /* Private helper method(s). */
        void garbage_collect(BinaryNode<T> *cur_root);

    public:
        /* Constructor(s) / destructor. */
        explicit BinarySearchTree(BinaryNode<T> *newRoot = nullptr);

        ~BinarySearchTree();
    
        /* Getter(s) / setter(s). */
        bool setRoot(BinaryNode<T> *newRoot);

        /* Public instance methods. */
        bool isEmpty() const;
        void insert(T data);

        template <typename Processor>
        void r_inorder(Processor func); // Recursive traverse wrapper.

        // 'r_traverse' recursive helper.
        template <typename Processor>
        void r_inorder(BinaryNode<T> *cur_root, Processor func);

        template <typename Processor>
        void i_inorder(Processor func); // Iterative traverse.

};

/* Constructor(s) / destructor. */
template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinaryNode<T> *newRoot) 
    : root{ newRoot } {
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete root;
}

/* Getter(s) / setter(s). */
template <typename T>
bool BinarySearchTree<T>::setRoot(BinaryNode<T> *newRoot) {
    root = newRoot;
    return true;
}

/* Public instance methods. */
template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T data) {
    BinaryNode<T> *new_node = new BinaryNode<T>;
    BinaryNode<T> *parent;
    BinaryNode<T> *cur;

    new_node->element = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    parent = nullptr;

    if (isEmpty())
        root = new_node;
    else {
        cur = root; 

        // Find new_node's parent node.
        while (cur) {
            parent = cur;
            if (new_node->element > cur->element)
                cur = cur->right;
            else
                cur = cur->left;
        }

        if (new_node->element < parent->element)
            parent->left = new_node;
        else
            parent->right = new_node;
    }

}

template <typename T>
template <typename Processor>
void BinarySearchTree<T>::r_inorder(Processor func) {
    r_inorder(root, func);
}

template <typename T>
template <typename Processor>
void BinarySearchTree<T>::r_inorder(BinaryNode<T> *cur_root, Processor func) { 
    if (cur_root == nullptr)
        return;

    r_inorder(cur_root->left, func);
    func(cur_root->element);
    r_inorder(cur_root->right, func);
}
 
template <typename T>
template <typename Processor>
void BinarySearchTree<T>::i_inorder(Processor func) {
    stack<BinaryNode<T>*> visited;
    BinaryNode<T> *node_p;

    node_p = root;
    while (true) {

        if (node_p == nullptr) {

            // Done!
            if (visited.empty())
                break;

            node_p = visited.top();
            visited.pop();

            // Process element.
            func(node_p->element);

            node_p = node_p->right;

        } else {
            visited.push(node_p);
            node_p = node_p->left;
        }
    }
}

#endif /* BINARY_SEARCH_TREE_H */

