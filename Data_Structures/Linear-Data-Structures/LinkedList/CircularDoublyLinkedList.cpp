#include <iostream>
#include <cassert>

class CircularDoublyLinkedList{
private:
    struct Node{
        int data{};
        Node* next;
        Node* prev;

        Node(int val):next{nullptr}, prev{nullptr}{
            data = val;
        }
    };

    Node* head;
    Node* tail;
    int size{};

public:
    CircularDoublyLinkedList():head{nullptr}, tail{nullptr} {}

    ~CircularDoublyLinkedList(){
        if (!head) return;

        Node* curr = head->next;

        while(curr != head){
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
    }

     bool isEmpty() {return size == 0;}
     int getSize() {return size;}

     void pushFront(int val){

        Node* newNode = new Node{val};

        if(!head){
            head = tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }else{
            newNode->next = head;
            newNode->prev = tail;

            head->prev = newNode;
            tail->next = newNode;

            head = newNode;
        }

        size++;
     }

     void pushMid(int key , int val){
        Node* newNode = new Node{val};

        if(!head){
            head = tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            size++;
            return;
        }

        Node* curr = head;

        do{
            if(curr->data == key) break;
            curr = curr->next;
        }while(curr != head);

        if(curr->data != key){
            delete newNode;
            pushBack(val);
            return;
        }

        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;

        if(curr == tail){
            tail = newNode;
        }

        size++;
     }

     void pushBack(int val){

        Node* newNode = new Node{val};

        if(!tail){
            head = tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }else{
            newNode->next = head;
            newNode->prev = tail;

            tail->next = newNode;
            head->prev = newNode;

            tail = newNode;
        }
        size++;
     }

     void popFront(){
        if(!head) return;

        if(head == tail){
            delete head;
            head = tail = nullptr;
        }else{
            Node* temp = head;
            head = head->next;

            head->prev = tail;
            tail->next = head;

            delete temp;
        }
        size--;
     }

     void popBack(){
        if(!tail) return;

        if(tail == head){
            delete tail;
            head = tail = nullptr;
        }else{
            Node* temp = tail;
            tail = tail->prev;

            head->prev = tail;
            tail->next = head;

            delete temp;
        }

        size--;
     }

     void printForward(){

        if(!head) return;

        Node* curr = head;
        do{
            std::cout << curr->data << " ";
            curr = curr->next;
        }while(curr != head);

        std::cout<< "\n";
    }

    void printBackward(){

        if(!tail) return;
        
        Node* curr = tail;
        do {
            std::cout << curr->data << " ";
            curr = curr->prev;
        }while(curr != head);

        std::cout << "\n";
    }
};


int main(){

     CircularDoublyLinkedList cdll;

    // ---- 1. Empty list tests ----
    assert(cdll.isEmpty());
    assert(cdll.getSize() == 0);

    std::cout << "Empty list tests passed\n";

    // ---- 2. Single node tests ----
    cdll.pushFront(10);
    assert(!cdll.isEmpty());
    assert(cdll.getSize() == 1);

    std::cout << "Single node forward: ";
    cdll.printForward();      // Expected: 10
    std::cout << "Single node backward: ";
    cdll.printBackward();     // Expected: 10

    // ---- 3. pushFront & pushBack ----
    cdll.pushFront(20);   // 20 10
    cdll.pushBack(30);    // 20 10 30
    cdll.pushBack(40);    // 20 10 30 40

    std::cout << "After pushFront/pushBack forward: ";
    cdll.printForward();      // Expected: 20 10 30 40
    std::cout << "Backward: ";
    cdll.printBackward();     // Expected: 40 30 10 20

    assert(cdll.getSize() == 4);

    // ---- 4. pushMid tests ----
    cdll.pushMid(10, 15);   // insert after 10
    cdll.pushMid(40, 50);   // insert after tail
    cdll.pushMid(999, 60);  // key not found -> pushBack

    std::cout << "After pushMid forward: ";
    cdll.printForward();
    // Expected: 20 10 15 30 40 50 60

    std::cout << "Backward: ";
    cdll.printBackward();
    // Expected: 60 50 40 30 15 10 20

    assert(cdll.getSize() == 7);

    // ---- 5. popFront ----
    cdll.popFront(); // remove 20
    std::cout << "After popFront: ";
    cdll.printForward(); // Expected: 10 15 30 40 50 60
    assert(cdll.getSize() == 6);

    // ---- 6. popBack ----
    cdll.popBack(); // remove 60
    std::cout << "After popBack: ";
    cdll.printForward(); // Expected: 10 15 30 40 50
    assert(cdll.getSize() == 5);

    // ---- 7. Remove until empty ----
    while (!cdll.isEmpty()) {
        cdll.popFront();
    }

    assert(cdll.getSize() == 0);
    assert(cdll.isEmpty());

    std::cout << "After clearing list: ";
    cdll.printForward();  // Expected: nothing

    std::cout << "\nAll Circular Doubly Linked List tests passed!\n";

    return 0;
}