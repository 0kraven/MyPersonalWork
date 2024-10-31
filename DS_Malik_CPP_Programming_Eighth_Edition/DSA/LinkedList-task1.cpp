#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int data = 0, node* next = nullptr) : data(data), next(next) { }
};

class linkedlist{
    private:
        node* head;

    public:
        linkedlist():head(nullptr) {}

        void insert_at_head(int data) {
            node* newNode = new node(data);
            newNode->next = head;
            head = newNode;
        }
        void insert_at_tail(int data) {
            if(!head){
                cout << "ERROR: Linked list is empty.\n";
                return;
            }
            node* temp = head;
            while (temp->next)temp = temp->next;
            node* newNode = new node(data);
            temp->next = newNode;
        }
        void remove_at_head() {
            if(!head){
                cout << "ERROR: Linked List is empty.\n";
                return;
            }
            node* temp = head;
            head = head->next;
            delete temp;
            temp  = nullptr;
        
        }
        void remove_at_tail() {
            if(!head){
                cout << "ERROR: Linked List is empty.\n";
                return;
            }
            node* temp = head;
            while(temp->next->next)temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
            
        }
        void display() {
            node* temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        void insert_at_position(int data, int position) {
            if(!head || position <= 0) {
                cout << "ERROR: Invalid position.\n";
                return;
            }
            node* temp = head;
            while(--position)
            {   
                if(!temp->next)return;
                temp = temp->next;

            }
            node* newNode = new node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        ~linkedlist() {
            node* temp = head;
            while(temp){
                node* trash = temp->next;
                delete temp;
                temp = trash;
            }
        }
};

int main() {
    linkedlist l1;
    l1.insert_at_head(0);
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_head(10);
    l1.insert_at_head(11);
    l1.insert_at_head(12);
    l1.insert_at_position(3, 2);
    l1.remove_at_head();
    l1.remove_at_tail();
    l1.display(); // Output: 0 1 3 2
}