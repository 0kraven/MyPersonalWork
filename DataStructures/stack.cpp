#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node(int data = 0, node* next = nullptr) : data(data), next(next) { }
};
class Stack{
    private:
        node* head;
        int size;
        int length;
    public:

        Stack(int size = 10):head(nullptr), size(size), length(0) {}
        // it will add an element in the stack
        void push(int data){
            if(length == size) {
                cout << "Stack overflow";
                return;
            }
            node* newNode = new node(data);
            newNode->next = head;
            head = newNode;
            length++;
        }
        // it will remove an element from the stack
        int pop(){
            if(head == nullptr) return -1;
            int poppedData = head->data;
            node* temp = head;
            head = head->next;
            delete temp;
            length--;
            return poppedData;

        }
        int top() {
            if(head == nullptr) return -1;
            return head->data;
        }
        bool isEmpty(){
            return head == nullptr;
        }
        
        ~Stack(){
            while(!isEmpty()){
                pop();
            }
        }
};
