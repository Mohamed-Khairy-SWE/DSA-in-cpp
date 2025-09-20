/*
    1. Intuitive Explanation
    
    Think of a train: each coach has some passengers(the data) and a connector
    (a pointer) to the next coach. Unlike an array(where coaches are lined up neatly, side
    by side), the train coaches in a linked list can be scattered all around , but each one
    knows who comes after it.

    that's singly linked list:

    Each node stores data and a pointer to the next node.
    The list starts at a special pointer called the head.
    The the last node pointer is NULL (indicating the end)



    2. Real-world Use Cases

    - Dynamic memory usage: When you don't know the number of items ahead of time
    (like playlist queues, undo/redo in editors)

    - Inest/delete operation: much faster than arrays when modifying in the middle

    - Hash tables and adjacency lists: often uses linked list internally 
    for collision handling or graph edges.

    - Low Level system: OS process scheduling, memory allocation tracking


    3. step by step breakdown

        1. Node structure: Contains data + pointer to next node.

        2. Head pointer: Marks the start of the list 

        3. Traversal: start from head -> follow next pointers until NULL

        4. Insertion:
            .At head: make a new node point to current head, update
            head.

            .At tail: traverse to end , update last node's pointer

            .At middle: rewire pointers around the insertion point
        
        5. Deletion:
            . At head: move head to nect node

            . At tail/middle: adjust previous node's next to skip the deleted node

    4. Complexity Analysis
        Operation	            Time                    Complexity	Space Complexity
        Insert at head	        O(1)	                O(1)
        Insert at tail	        O(n)(or O(1) if tail    O(1)
                                is head)	
        Insert after node	    O(n)(search)	        O(1)
        Delete node (by value)	O(n)	                O(1)
        Search	                O(n)	                O(1)
        Traverse/Display	    O(n)	                O(1)
*/

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