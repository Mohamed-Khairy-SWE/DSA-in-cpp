
#include <iostream>
#include <cassert>

using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val): data(val) , prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr) , tail(nullptr) , size(0) {}

    ~DoublyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }


    // Insert at front
    void pushFront(int val) {
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Insert val after the node containing 'key'
    void pushMid(int key, int val) {
        Node* newNode = new Node(val);

        
        if (!head) {
            head = tail = newNode;
            size++;
            return;
        }

        
        Node* curr = head;
        while (curr && curr->data != key) {
            curr = curr->next;
        }

        
        if (!curr) {
            pushBack(val);
            return;
        }

        
        newNode->next = curr->next;
        newNode->prev = curr;

        if (curr->next) {
            curr->next->prev = newNode;
        } else {
            tail = newNode; 
        }

        curr->next = newNode;
        size++;
    }


    // Insert at back
    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    // Delete from front
    void popFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size--;
    }

    // Delete from back
    void popBack() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
    }

    // Print list forward
    void printForward() const {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    // Print list backward
    void printBackward() const {
        Node* curr = tail;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << "\n";
    }
};

// ----------- Driver & Tests -------------
int main() {
    DoublyLinkedList dll;

    // Test insertions
    dll.pushFront(10);
    dll.pushFront(20);
    dll.pushBack(30);
    dll.pushBack(40);

    cout << "Forward: ";
    dll.printForward();     // Expected: 20 10 30 40
    cout << "Backward: ";
    dll.printBackward();    // Expected: 40 30 10 20

    // Test deletions
    dll.popFront();         // Remove 20
    dll.popBack();          // Remove 40

    cout << "After pops forward: ";
    dll.printForward();     // Expected: 10 30

    assert(dll.getSize() == 2);
    cout << "All test cases passed!\n";

    return 0;
}

