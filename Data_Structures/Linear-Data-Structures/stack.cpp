/*
    1 — Intuitive explanation


        A stack is a linear collection that follows LIFO (Last In, First Out). You push items onto the top and pop items from the top. Think of a stack of plates — you add and remove from the top.

        Two common internal representations:

        Vector-backed stack: the stack sits on top of a dynamic array (e.g., std::vector). Push appends at the end, pop removes the last element.

        Linked-list stack: the stack is a singly linked list where the head node is the top of the stack. Push inserts a new head, pop removes the head.


    2 — Real-world use cases


        Function call stack / recursion (language runtimes).

        Undo/redo systems (maintain history).

        Depth-first search (DFS) algorithms.

        Expression evaluation (infix → postfix → evaluate).

        Backtracking (e.g., solving puzzles, constraint search).

        Browser history (back stack).

        Any place where you need reverse order processing.


    3 — How the data structure works (step-by-step)


        Generic operations: push(x), pop(), top() (or peek()), size(), empty().

        Vector-backed:

        push(x) → append to end. If capacity is exceeded, vector resizes (usually doubles capacity) and copies/moves elements to new storage (costly occasionally).

        pop() → remove last element (object destructor, no reallocation).

        top() → return element at data.back().

        Linked-list:

        Node: { value, next }.

        Top pointer points to head node.

        push(x) → allocate a new node, set its next to current head, set head = new node.

        pop() → remove head node, set head = old_head->next, deallocate old node.

        top() → access head->value.
*/

#include <iostream>
#include <vector>

using namespace std;


// -------------------------
// Stack using std::vector
// -------------------------
class StackVector {
private:
    vector<int> stack;

public:
    void push(int val) {
        stack.push_back(val);
    }

    void pop(){
        if (stack.empty()){
            cout << "stack is empty. cannot pop. \n";
            return;
        }
        stack.pop_back();
    }

    int peekTop() {
        if (stack.empty()){
            cout << "stack is empty.\n";
            return -1;
        }
        return stack.back();
    }

    bool isEmpty() {
        return stack.empty();
    }

    int size() {
        return stack.size();
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class StackLinkedList {
private:
    Node* topNode;

public:
    StackLinkedList(): topNode(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (!topNode) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (!topNode) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return !topNode;
    }

    int size() {
        int count = 0;
        Node* temp = topNode;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    StackVector sv;
    cout << "--- Stack Using Vector ---\n";

    sv.push(10);
    sv.push(20);
    sv.push(30);

    cout << "Top element: " << sv.peekTop() << endl; // 30
    sv.pop();
    cout << "Top after pop: " << sv.peekTop() << endl; // 20

    cout << "Size: " << sv.size() << endl; // 2
    cout << "Is empty? " << (sv.isEmpty() ? "Yes" : "No") << endl;

    // Edge case
    sv.pop(); sv.pop(); sv.pop(); // test popping empty


    StackLinkedList s;
    cout << "--- Stack Using Linked List ---\n";

    s.push(5);
    s.push(10);
    s.push(15);

    cout << "Top element: " << s.top() << endl; // 15
    s.pop();
    cout << "Top after pop: " << s.top() << endl; // 10

    cout << "Size: " << s.size() << endl; // 2
    cout << "Is empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    // Edge case
    s.pop(); s.pop(); s.pop(); // test popping empty

    return 0;
}

