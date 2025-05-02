#include <iostream>

const int TABLE_SIZE = 10;
const double A = 0.6180339887; // Fractional part of the golden ratio (a good choice for A)


using namespace std;

class Hash_Table {

private:
        int table[TABLE_SIZE];
public:
        Hash_Table(){
            for(int i =0; i < TABLE_SIZE; i++){
                table[i] = -1;
            }
        }

        int multiplication_method(int key) {
            double product = key * A;
            double fractional = product - static_cast<int>(product);
            return static_cast<int>(TABLE_SIZE * fractional);
        }

        void insert(int key) {
            int index = multiplication_method(key);
            if (table[index] == -1) {
                table[index] = key;
                std::cout << "Inserted " << key << " at index " << index << "\n";
            } else {
                std::cout << "Collision occurred at index " << index << " for key " << key << "\n";
            }
        }
    
        void display() {
            for (int i = 0; i < TABLE_SIZE; ++i) {
                if (table[i] == -1)
                    std::cout << "[" << i << "] : EMPTY\n";
                else
                    std::cout << "[" << i << "] : " << table[i] << "\n";
            }
        }
    };
    

    

    int main() {
        Hash_Table ht;
    
        ht.insert(10);
        ht.insert(22);
        ht.insert(31);
        ht.insert(4);
        ht.insert(15);
        ht.insert(28);
    
        ht.display();
    
        return 0;
    }
