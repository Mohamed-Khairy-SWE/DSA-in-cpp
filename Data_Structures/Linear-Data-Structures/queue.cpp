#include <iostream>


struct Node {
    int data {};
    Node* next {};
    Node(int val) : data{val} , next {nullptr} {}
};

class LinkedListQueue {
private:
    Node* m_front {};
    Node* m_back {};
public:
    LinkedListQueue()
       : m_front{nullptr},
         m_back{nullptr}
        {

        }

    void enqueue(int val){

        Node* newNode = new Node(val);

        if(m_back == nullptr){
            m_front = m_back = newNode;
            return;
        }

        m_back->next = newNode;
        m_back = newNode;
    }

    void dequeue(){
        
        if(m_front == nullptr){
            std::cout << "the queue is empty";
            return;
        }

        Node* temp = m_front;
        m_front = m_front->next;

        if(m_front == nullptr)
            m_back = nullptr;
        
        delete temp;
    }

    int peek(){
        if(m_front == nullptr){
            std::cout << "the queue is empty";
            return -1;
        }

        return m_front->data;
    }


    bool isEmpty(){
        return m_front == nullptr;
    }


    void print(){
        Node* curr = m_front;
        std::cout << "Queue: ";
        while(curr){
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }
};

int main() {

    LinkedListQueue Q {};

    Q.enqueue(12);
    Q.enqueue(23);
    Q.enqueue(43);
    Q.enqueue(54);
    Q.enqueue(66);

    Q.print();

    Q.dequeue();

   std::cout<< "the front element: " <<  Q.peek() << "\n";

    if(Q.isEmpty()){
        std::cout << "queue is empty\n";
    }else{
        std::cout << "queue is full\n";
    }


    Q.dequeue();
    Q.dequeue();

    Q.print();



    return 0;
}