

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public: 
    SinglyLinkedList(){
        head = nullptr;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next= newNode;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "key not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int val) {
        if (!head) return;
        if(head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val) temp = temp->next;
        if(!temp->next) {
            cout << "Value not found!\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    bool search(int val){
        Node* temp  = head;
        while (temp) {
            if(temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;

    cout << "Inserting at head: ";
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.display();

    cout << "Inserting at tail: ";
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.display();

    cout << "Inserting after 20: ";
    list.insertAfter(20, 25);
    list.display();

    cout << "Delete node 30: ";
    list.deleteNode(30);
    list.display();

    cout << "Search 25: " << (list.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (list.search(100) ? "Found" : "Not Found") << endl;

    return 0;
}