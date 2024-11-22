#include<iostream>  
using namespace std;
struct node{
    int data;
    node* next;
    node(int data = 0, node* next = nullptr) : data(data), next(next) {}
};
class DQueue{
    private:
        node* front;
        node* rear;
        int size;
        int length;

    public:
        DQueue(node* front = nullptr, node* rear = nullptr) : front(front), rear(rear) {}
        // Adding an element at the front of the queue
        void addFront(int data){
            if(length == size) {
                cout << "Queue overflow";
                return;
            }
            node* newNode = new node(data);
            if(front == nullptr) {
                front = newNode;
                rear = newNode;
            }
            else {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
            length++;
        }
        // Adding an element at the rear of the queue
        void addRear(int data){
            if(length == size) {
                cout << "Queue overflow";
                return;
            }
            node* newNode = new node(data);
            if(rear == nullptr) {
                front = newNode;
                rear = newNode;
            } else {
                rear->next = newNode;
                newNode->prev = rear;
                rear = newNode;
            }
            length++;
        }
        // Removing an element from the front of the queue
        int removeFront(){
            if(front == nullptr) return -1;
            int dequeuedData = front->data;
            node* temp = front;
            front = front->next;
            if(front) front->prev = nullptr;
            delete temp;
            length--;
            if(front == nullptr) rear = nullptr;
            return dequeuedData;
        }
        // Removing an element from the rear of the queue
        int removeRear(){
            if(rear == nullptr) return -1;
            int dequeuedData = rear->data;
            node* temp = rear;
            rear = rear->prev;
            if(rear) rear->next = nullptr;
            delete temp;
            length--;
            if(rear == nullptr) front = nullptr;
            return dequeuedData;
        }
        // Displaying the queue
        void display(){
            node* temp = front;
            while(temp!=nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        // Checking if the queue is empty
        bool isEmpty(){
            return front == nullptr;
        }
        ~DQueue(){
            while(!isEmpty()){
                removeFront();
            }
        }
};