#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int data = 0, node* left = 0, node* right = 0) : data(data), left(left), right(right) {}
};

class Tree{
    private:
        node* root;
        
        node* insert_helper(node* Node  = 0, int data = 0) {
            if(Node == 0) return new node(data);
            if(data < node->data) node->left = insert_helper(Node->left, data);
            else node->right = insert_helper(Node->right, data);
            return node;
        }
    public:
        
        Tree(node* root) : root(root) {}


        void insert(int data) {
            root = insert_helper(root, data); // root is only updated when there is no root node
        }

};

int main() {

}