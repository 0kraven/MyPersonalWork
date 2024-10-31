#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
    node(int data = 0, node* next = nullptr, node* prev = nullptr) : data(data), next(next), prev(prev) {}
};

class DoubleLinkedList {
private:
    node* head;

public:
    DoubleLinkedList() : head(nullptr) {} 

    void insert_at_head(int data) {
        node* newNode = new node(data);
        if (head) { 
            newNode->next = head; 
            head->prev = newNode; 
        } else {
            newNode->next = nullptr; 
        }
        head = newNode; 
        head->prev = nullptr; 
    }

    void insert_at_tail(int data) {
        if (head == nullptr) {
            insert_at_head(data); 
            return;
        }
        node* newNode = new node(data);
        node* temp = head;
        while (temp->next) {
            temp = temp->next; 
        }
        temp->next = newNode; 
        newNode->prev = temp; 
    }

    void remove_at_head() {
        if (!head) {
            cout << "ERROR: Linked List is empty.\n";
            return;
        }
        
        node* temp = head; 
        head = head->next; 
        
        if (head) {
            head->prev = nullptr; 
        }

        delete temp; 
    }

    void remove_at_tail() {
        if (!head) {
            cout << "ERROR: Linked List is empty.\n";
            return;
        }

        if (!head->next) { 
            delete head;
            head = nullptr; 
            return;
        }
        
        node* temp = head;
        while (temp->next) {
            temp = temp->next; 
        }
        
        
        if (temp->prev) {
            temp->prev->next = nullptr; 
        }
        
        delete temp; 
    }

    void display() {
        if (!head) {
            cout << "ERROR: Linked List is empty.\n";
            return;
        }
        node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl; 
    }

    ~DoubleLinkedList() {
        while (head) { 
            remove_at_head();
        }
    }
};

int main() {
    DoubleLinkedList l1;
    l1.remove_at_head(); 
    l1.remove_at_tail(); 
    l1.insert_at_head(0);
    l1.remove_at_tail(); 
    l1.insert_at_head(1);
    l1.remove_at_head(); 
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.display(); 
    
    return 0;
}