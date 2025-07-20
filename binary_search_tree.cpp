#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->key == key)
        return true;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    int target = 40;
    if (search(root, target))
        cout << "Key " << target << " found in BST." << endl;
    else
        cout << "Key " << target << " not found in BST." << endl;

    return 0;
}
