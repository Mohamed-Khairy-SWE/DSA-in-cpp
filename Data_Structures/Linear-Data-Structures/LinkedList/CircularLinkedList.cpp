/*
    1. Intuitive Explanation

        A Circular Linked List (CLL) is just like a normal linked list, except:

        The last node points back to the first node (instead of pointing to NULL).

        This forms a circle of nodes, where you can start at any node and keep looping around.

        Imagine a group of friends standing in a circle passing a ball. There’s no “end friend” — eventually the ball comes back to the first friend.

    2. Real-world Use Cases

        Round-robin scheduling (OS): The CPU scheduler cycles through processes in a loop.

        Multiplayer games: Players take turns in a cycle.

        Buffer management: Circular queues (like in networking) often use circular lists under the hood.

        Music/playlist apps: When repeat mode is on, the playlist loops back to the start.

    3. Step-by-Step Breakdown

        Each node contains: data and a next pointer.

        In a singly circular linked list, only next pointers exist, and the last node links back to head.

        In a doubly circular linked list, each node has both next and prev, and both directions loop back.

        Basic Operations:

            Insertion

                At the beginning: new node’s next = head, last node’s next = new node.

                At the end: traverse to last, then adjust its next.

                In the middle: link new node between two existing nodes.

            Deletion

                Adjust neighbors so they “skip” the deleted node.

                Special care if deleting head or the only node.

            Traversal

                Use do { … } while (curr != head) to ensure we don’t loop infinitely.
*/

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