#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->value << " ";
    }
}

int main() {
    Node* root = nullptr;
    int values[] = {9, 10, 11, 15, 17, 30, 35, 40};

    for (int value : values) {
        root = insert(root, value);
    }

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
