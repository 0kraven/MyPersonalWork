#include <iostream>
using namespace std;

// Binary Tree Node Class
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Tree Class
class BinaryTree {
private:
    

    // Helper function for recursive insertion
    TreeNode* insert(TreeNode* node, int value) {
        if (!node) return new TreeNode(value);
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function for recursive search
    bool search(TreeNode* node, int value) {
        if (!node) return false;
        if (node->data == value) return true;
        if (value < node->data) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

    // Helper function for inorder traversal
    void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Helper function for preorder traversal
    void preorderTraversal(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Helper function for postorder traversal
    void postorderTraversal(TreeNode* node) {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    // Helper function to find the minimum node in a tree
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (!node) return nullptr;

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node to be deleted found
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Helper function to calculate the height of the tree
    int height(TreeNode* node) {
        if (!node) return -1;
        return 1 + max(height(node->left), height(node->right));
    }

public:
    TreeNode* root;
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Insert function
    void insert(int value) {
        root = insert(root, value);
    }

    // Search function
    bool search(int value) {
        return search(root, value);
    }

    // Delete function
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Inorder Traversal
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    // Preorder Traversal
    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    // Postorder Traversal
    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }

    // Height of the tree
    int getHeight() {
        return height(root);
    }
};

// Main function
int main() {
    BinaryTree tree;

    // Insert values


    // Traversals
    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    // Search
    cout << "Search 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search 20: " << (tree.search(20) ? "Found" : "Not Found") << endl;

    // Height
    cout << "Height of tree: " << tree.getHeight() << endl;

    // Delete a node
    tree.deleteValue(10);
    cout << "Inorder Traversal after deleting 10: ";
    tree.inorder();
    cout << "root: " << tree.root->data << endl;
    return 0;
}
