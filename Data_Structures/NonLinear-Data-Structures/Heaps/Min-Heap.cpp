#include <iostream>
#include <vector>
#include <cmath>

class MinHeap {
private:
    std::vector<int> heap{};
    

    void heapifyUp(){
        int i = heap.size() - 1;
        while(i > 0){
            int parent {(i - 1)/2};
            if(heap[i] < heap[parent]){
                std::swap(heap[i] , heap[parent]);
                i = parent;
            }else{
                break;
            }
        }
    }

    void heapifyDown() {
        
        int i {0};
        int length = heap.size();
        while(i < length){
            int leftChild {2*i + 1};
            int rightChild {2*i + 2};
            int smallestChild {i};
           
            if(leftChild < length && heap[leftChild] < heap[smallestChild]){
                smallestChild = leftChild;
            }

            if(rightChild < length && heap[rightChild] < heap[smallestChild]){
                smallestChild = rightChild;
            }

            if(smallestChild != i){
                std::swap(heap[i] , heap[smallestChild]);
                i = smallestChild; 
            }else{
                break;
            }
        }
    }
public:
    void insert(int val){
        heap.push_back(val);
        heapifyUp();
    }

    int getMinimum(){
        if(heap.empty()){
            throw std::runtime_error("heap is empty");
        }

        return heap[0];
    }

    void RemoveMinimum(){
        if(heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown();
    }

    void DisplayHeap(){
        for(const auto& num : heap){
            std::cout << num << " ";
        }
        std::cout<< '\n';
    }

};


int main() {
    MinHeap h;

    h.insert(60);
    h.insert(44);
    h.insert(20);
    h.insert(18);
    h.insert(12);
    h.insert(1);

    h.DisplayHeap();

    std::cout << h.getMinimum() << '\n';



    h.RemoveMinimum();

    h.DisplayHeap();
    return 0;
    
}