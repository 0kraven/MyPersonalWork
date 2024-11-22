#include<iostream>
using namespace std;

struct nodeTree {
    int data;
    nodeTree* left;
    nodeTree* right;
    nodeTree(int data) : data(data), left(nullptr), right(nullptr) {}
}
class BSTree{
    private:
        nodeTree* root;
        nodeTree* insertHelper(nodeTree* node, int data){
            if(node == nullptr) return new nodeTree(data);
            if(data < node->data) node->left = insertHelper(node->left, data);
            else if(data > node->data) node->right = insertHelper(node->right, data);
            return node;
        }
        void inorderTraversalHelper(nodeTree* node){
            if(node!=nullptr){
                inorderTraversalHelper(node->left);
                cout << node->data << " ";
                inorderTraversalHelper(node->right);
            }
        }
        void preorderTraversalHelper(nodeTree* node){
            if(node!=nullptr){
                cout << node->data << " ";
                preorderTraversalHelper(node->left);
                preorderTraversalHelper(node->right);
            }
        }
        void postorderTraversalHelper(nodeTree* node){
            if(node!=nullptr){
                postorderTraversalHelper(node->left);
                postorderTraversalHelper(node->right);
                cout << node->data << " ";
            }
        }
        bool searchHelper(nodeTree* node, int data){
            if(node == nullptr) return false;
            if(data < node->data) return searchHelper(node->left, data);
            else if(data > node->data) return searchHelper(node->right, data);
            return true;
        }
        nodeTree* minValueNodeHelper(nodeTree* node){
            while(node && node->left!=nullptr) node = node->left;
            return node;
        }
        nodeTree* deleteNodeHelper(nodeTree* root, int data){
            if(root == nullptr) return root;
            if(data < root->data) root->left = deleteNodeHelper(root->left, data);
            else if(data > root->data) root->right = deleteNodeHelper(root->right, data);
            else{
                if(root->left == nullptr) return root->right;
                else if(root->right == nullptr) return root->left;
                nodeTree* temp = minValueNodeHelper(root->right);
                root->data = temp->data;
                root->right = deleteNodeHelper(root->right, temp->data);
            }
            return root;
        }
        

    public:
        BSTree() : root(nullptr) {}
        void insert(int data){
            root = insertHelper(root, data);
        }
        void displayInorder(){
            inorderTraversalHelper(root);
        }
        void displayPreorder(){
            preorderTraversalHelper(root);
        }
        void displayPostorder(){
            postorderTraversalHelper(root);
        }
        bool search(int data){
            return searchHelper(root, data);
        }
        void remove(int data){
            root = deleteNodeHelper(root, data);
        }
        void display(){
            cout << "Inorder traversal: ";
            displayInorder();
            cout << "\nPreorder traversal: ";
            displayPreorder();
            cout << "\nPostorder traversal: ";
            displayPostorder();
        }
        
}