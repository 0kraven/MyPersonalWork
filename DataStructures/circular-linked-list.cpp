#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int data = 0, node* next = nullptr) : data(data), next(next) {}
};

class circularLinkedList {
private:
    node* head;

public:
    circularLinkedList() : head(nullptr) {}

    void insert_at_head(int data) {
        node* newNode = new node(data);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
    }

    void insert_at_tail(int data) {
        node* newNode = new node(data);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void remove_at_head() {
        if (!head) {
            cout << "ERROR: Linked List is empty.\n";
            return;
        }
        node* temp = head;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        head = head->next;
        node* tail = head;
        while (tail->next != temp) {
            tail = tail->next;
        }
        tail->next = head;
        delete temp;
    }

    void remove_at_tail() {
        if (!head) {
            cout << "ERROR: Linked List is empty.\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
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
            if (temp == head) {
                break;
            }
        }
        cout << endl;
    }

    
};

int main() {
    circularLinkedList list;
    list.insert_at_head(5);
    list.insert_at_tail(10);
    list.insert_at_tail(15);
    list.insert_at_head(20);

    list.remove_at_head();

    list.remove_at_tail();
    list.display();

    return 0;
}
