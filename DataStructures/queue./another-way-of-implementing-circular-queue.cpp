#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;   // Array to hold the queue
    int front;    // Index of the front element
    int rear;     // Index of the rear element
    int size;     // Current number of elements in the queue
    int capacity; // Maximum capacity of the queue

public:
    // Constructor
    CircularQueue(int capacity) : front(-1), rear(-1), size(0), capacity(capacity) {
        queue = new int[capacity];
    }

    // Destructor
    ~CircularQueue() {
        delete[] queue;
    }

    // Add an element to the queue
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
            return;
        }
        // If the queue is empty, update the front pointer
        if (isEmpty()) {
            front = 0;
        }
        // Increment rear in a circular manner
        rear = (rear + 1) % capacity;
        queue[rear] = data;
        size++;
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        int dequeuedData = queue[front];
        // If there's only one element, reset the queue
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Increment front in a circular manner
            front = (front + 1) % capacity;
        }
        size--;
        return dequeuedData;
    }

    // Peek the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
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
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};


