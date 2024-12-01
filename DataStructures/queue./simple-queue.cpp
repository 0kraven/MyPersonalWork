#include<iostream>
using namespace std;

class node{
    int data;
    node* next;

    node(int data = 0, node* next = nullptr) : data(data), next(next) {}
}
class Queue{
    private:
        node* front;
        node* rear;
        int size;
        int length;
    public:
        Queue(int size = 10): front(nullptr), rear(nullptr), size(size), length(0) {}
        void enqueue(int data){
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
                rear = newNode;
            }
            length++;
        }
        int dequeue(){
            if(front == nullptr) return -1;
            int dequeuedData = front->data;
            node* temp = front;
            front = front->next;
            delete temp;
            length--;
            if(front == nullptr) rear = nullptr;
            return dequeuedData;
        }
        int front() {
            if(front == nullptr) return -1;
            return front->data;
        }
        int rear() {
            if(rear == nullptr) return -1;
            return rear->data;
        }
        int size() {
            return length;
        }
        bool isEmpty(){
            return front == nullptr;
        }
        ~Queue(){
            while(!isEmpty()){
                dequeue();
            }
        }
}
