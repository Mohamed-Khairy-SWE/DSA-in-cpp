#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap{};

    void heapifyUp(){
        int i = heap.size() -1;
        while(i > 0){
            int parent = (i - 1)/2;

            if(heap[i] > heap[parent]){
                std::swap(heap[i] , heap[parent]);
                i = parent;
            }else{
                break;
            }
        }
    }

    void heapifyDown(){
        int i {0};
        int length = heap.size();
        while (i < length){
            int leftChild { 2 * i +1};
            int rightChild {2 * i +2};
            int largestChild {i};

            if(leftChild < length && heap[largestChild] < heap[leftChild])
                largestChild = leftChild;
            
            if(rightChild < length && heap[largestChild] < heap[rightChild])
                largestChild = rightChild;
            
            if(largestChild != i){
                std::swap(heap[i], heap[largestChild]);
                i = largestChild;
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

    int getMaxmum(){
        if(heap.empty())
            throw std::runtime_error("the heap empty");
        
        return heap[0];
    }

    void RemoveMaxmum(){
        if(heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown();
    }

    void DisplayHeap(){
        for(const auto& num : heap){
            std::cout << num << " ";
        }
        std::cout << '\n';
    }

};


int main() {
    MaxHeap h;
    
    h.insert(1);
    h.insert(18);
    h.insert(25);
    h.insert(33);
    h.insert(45);
    h.insert(59);
    h.insert(68);

    h.DisplayHeap();

    std::cout << h.getMaxmum() << '\n';

    h.RemoveMaxmum();
    h.DisplayHeap();



    return 0;
}