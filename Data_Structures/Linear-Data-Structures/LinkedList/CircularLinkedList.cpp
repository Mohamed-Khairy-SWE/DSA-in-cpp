

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList(): head(nullptr) {}

    void insertBegin(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void deleteNode(int val) {
        if (!head) return;

        Node* curr = head;
        Node* prev = nullptr;

        if(head->data == val){
            if(head->next == head){
                delete head;
                head = nullptr;
                return;
            }

            Node* last = head;
            while(last->next != head) last = last->next;

            last->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // otherwise search
        do {
            prev = curr;
            curr = curr->next;
            if(curr->data == val){
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);
    }

 void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }
};

// ---------------- DRIVER -----------------
int main() {
    CircularLinkedList cll;
    cll.insertEnd(10);
    cll.insertEnd(20);
    cll.insertEnd(30);
    cll.insertBegin(5);
    cll.display();  // Expected: 5 10 20 30

    cll.deleteNode(10);
    cll.display();  // Expected: 5 20 30

    cll.deleteNode(5);
    cll.display();  // Expected: 20 30

    cll.deleteNode(30);
    cll.display();  // Expected: 20

    cll.deleteNode(20);
    cll.display();  // Expected: List is empty

    return 0;
}