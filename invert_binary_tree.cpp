#include <iostream>

using namespace std;

// Binary tree node structure
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// Recursive function to invert the binary tree
void invertTree(Node* root) {
    if (root == nullptr) return;

    // Swap left and right children
    swap(root->left, root->right);

    // Recursively invert the children
    invertTree(root->left);
    invertTree(root->right);
}

// Helper function to print the tree in pre-order
void printPreOrder(Node* root) {
    if (root == nullptr) return;

    cout << root->value << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    // Example binary tree:
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Original tree (pre-order): ";
    printPreOrder(root);
    cout << endl;

    invertTree(root);

    cout << "Inverted tree (pre-order): ";
    printPreOrder(root);
    cout << endl;

    return 0;
}
