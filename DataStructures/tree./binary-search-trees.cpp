#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data = 0, Node* left = 0, Node* right = 0) : data(data), left(left), right(right) {}
};

class Tree{
    private:
        Node* root;
        
        Node* insert_helper(Node* node  = 0, int data = 0) {
            if(node == 0) return new Node(data);
            if(data < node->data) node->left = insert_helper(node->left, data);
            else node->right = insert_helper(node->right, data);
            return node;
        }

        // Pre-order
        void preorder_helper(Node* root) {
            if (root == nullptr) return;
            cout << root->data << " ";
            preorder_helper(root->left);
            preorder_helper(root->right);
        }

        // In-order
        void inorder_helper(Node* root) {
            if (root == nullptr) return;
            inorder_helper(root->left);
            cout << root->data << " ";
            inorder_helper(root->right);
        }

        // Post-order

        void postorder_helper(Node* root) {
            if (root == nullptr) return;
            postorder_helper(root->left);
            postorder_helper(root->right);
            cout << root->data << " ";
        }
        void levelorder_helper(Node *root) {
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                node* current = q.front();
                cout << current->data << " ";
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);  // push right child before left child to ensure left child is processed first in case of left-right-root order.  // if left child is processed first, it will print root before left and right child.  // if right child is processed first, it will print
            }

        }
    public:
        
        Tree(Node* root = 0) : root(root) {}


        void insert(int data) {
            root = insert_helper(root, data); // root is only updated when there is no root node
        }
        void preorder() {
            preorder_helper(root);
        }
        void inorder() {
            inorder_helper(root);
        }
        void postorder() {
            postorder_helper(root);
        }
        void levelorder() {
            levelorder_helper(root);
        }

};

int main() {
    Tree root;
    root.insert(50);
    root.insert(30);
    root.insert(20);
    root.insert(40);
    root.insert(70);
    root.insert(60);
    root.insert(80);
    cout << "Preorder traversal of the constructed tree is \n";
    root.preorder();
    cout << "\nInorder traversal of the constructed tree is \n";
    root.inorder();
    cout << "\nPostorder traversal of the constructed tree is \n";
    root.postorder();
    cout << "\nLevel order traversal of the constructed tree is \n";
    root.levelorder();
    return 0;
}