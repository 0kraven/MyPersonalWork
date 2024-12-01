#include<iostream>
using namespace std;

// Node class for the doubly linked list
class Node {
public:
    int data;     // Data stored in the node
    Node* next;   // Pointer to the next node
    Node* prev;   // Pointer to the previous node

    // Constructor to initialize a node
    Node(int data = 0, Node* next = nullptr, Node* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};

// CircularQueue class
class CircularQueue {
private:
    Node* front;    // Pointer to the front of the queue
    Node* rear;     // Pointer to the rear of the queue
    int size;       // Current size of the queue
    int capacity;   // Maximum capacity of the queue

public:
    // Constructor to initialize the queue
    CircularQueue(int capacity)
        : front(nullptr), rear(nullptr), size(0), capacity(capacity) {}

    // Add an element to the rear of the queue
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
            front->next = front;
            front->prev = front; // Pointing to itself
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            newNode->next = front;
            front->prev = newNode;
            rear = newNode;
        }
        size++;
    }

    // Remove an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        int dequeuedData = front->data;
        if (front == rear) { // Single element in the queue
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            front->prev = rear;
            rear->next = front;
            delete temp;
        }
        size--;
        return dequeuedData;
    }

    // Peek at the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        for (int i = 0; i < size; i++) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up the queue
    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
