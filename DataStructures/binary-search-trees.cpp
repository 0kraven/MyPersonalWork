#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int data = 0, node* left = nullptr, node* right = nullptr) : data(data), left(left), right(right) {}
};

class BSTree{
    private:
        node* root;
        node* insert_helper(node* Node, int data = 0) {
            if(!Node) {
                return new node(data);
            }
            else if(Node->data >= data) {
                Node->left = insert_helper(Node->left, data);
            }
            else if(Node->right == nullptr) {
                Node->right = insert_helper(Node->right,data);
            }
            return Node;
        }
        void inorder_helper(node* node) {
            if( node == nullptr ) {
                return;
            }
            inorder_helper(node->left);
            cout << node->data << " ";
            inorder_helper(node->right);
        }
    public:
        
        BSTree(node* root = nullptr) : root(root) {}
        void insert(int data = 0){
            root = insert_helper(root,data);
        }
        void inorder() {
            inorder_helper(root);
        }
};
int main() {

    BSTree root;
    root.insert(50);
    root.insert(30);
    root.insert(20);
    root.insert(40);
    root.insert(70);
    root.inorder();
}