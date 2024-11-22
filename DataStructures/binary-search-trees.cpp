#include <iostream>
using namespace std;

// Node structure to represent each node in the tree
struct Node {
    int value;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int key) {
        value = key;
        left = right = nullptr;
    }
};

// Binary Search Tree class
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Function to insert a new value into the BST
    void insert(int key) {
        root = insertHelper(root, key);
    }

    // Function to search a value in the BST
    bool search(int key) {
        return searchHelper(root, key) != nullptr;
    }

    // Function for inorder traversal of the BST
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    // Function to find the minimum value in the BST
    int minValue() {
        return minValueHelper(root);
    }

    // Function to find the maximum value in the BST
    int maxValue() {
        return maxValueHelper(root);
    }

private:
    // Helper function to insert a value recursively
    Node* insertHelper(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->value) {
            node->left = insertHelper(node->left, key);
        } else {
            node->right = insertHelper(node->right, key);
        }

        return node;
    }

    // Helper function to search a value recursively
    Node* searchHelper(Node* node, int key) {
        if (node == nullptr || node->value == key) {
            return node;
        }

        if (key < node->value) {
            return searchHelper(node->left, key);
        }

        return searchHelper(node->right, key);
    }

    // Helper function for inorder traversal
    void inorderHelper(Node* node) {
        if (node != nullptr) {
            inorderHelper(node->left);
            cout << node->value << " ";
            inorderHelper(node->right);
        }
    }

    // Helper function to find the minimum value
    int minValueHelper(Node* node) {
        if (node == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1;
        }

        while (node->left != nullptr) {
            node = node->left;
        }

        return node->value;
    }

    // Helper function to find the maximum value
    int maxValueHelper(Node* node) {
        if (node == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1;
        }

        while (node->right != nullptr) {
            node = node->right;
        }

        return node->value;
    }
};

// Main function to demonstrate the BST operations
int main() {
    BST bst;
    bst.insert(20);
    bst.insert(8);
    bst.insert(22);
    bst.insert(4);
    bst.insert(12);
    bst.insert(10);
    bst.insert(14);

    cout << "Inorder Traversal: ";
    bst.inorder();  // Output: 4 8 10 12 14 20 22

    cout << "Search for 10: " << (bst.search(10) ? "Found" : "Not Found") << endl; // Output: Found
    cout << "Search for 15: " << (bst.search(15) ? "Found" : "Not Found") << endl; // Output: Not Found

    cout << "Min Value: " << bst.minValue() << endl;  // Output: 4
    cout << "Max Value: " << bst.maxValue() << endl;  // Output: 22

    return 0;
}
