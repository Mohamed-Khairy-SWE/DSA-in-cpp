#include <iostream>

const int TABLE_SIZE = 10;


class Hash_Table {
private: 
    int table[TABLE_SIZE];

public:
    Hash_Table(){
        for(int i = 0; i <TABLE_SIZE; i++)
            table[i] = -1; // means it's empty
    }

    int mid_square_method(int key){
        long long squared = static_cast<long long>(key) * key; // I use long long to avoid overflow for larger keys.

        std::string squaredStr = std::to_string(squared);

        int len = squaredStr.length();

        int mid = len/2;

        std::string midDigite = squaredStr.substr(mid-1, 2);

        int index = std::stoi(midDigite) % TABLE_SIZE;

        return index;
    }

    void insert(int key){
        int index = mid_square_method(key);

        if(table[index] == -1 || table[index] == -2){
            table[index] = key;
            std::cout << "Inserted " << key << " at index " << index << "\n";
        }
        else{
            std::cout << "Collision occurred! Could not insert " << key << "\n";

        }
    }

    void remove(int key){
        int index = mid_square_method(key);

        if(table[index] == key){
            table[index] = -2; // means it's removed
            std::cout << "removed " << key << " at index " << index << "\n";
        }
        else{
            std::cout << "this place is already empty" << '\n';
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] == -1)
                std::cout << "[" << i << "] : EMPTY\n";
            else if (table[i] == -2)
                std::cout << "[" << i << "] : DELETED\n";
            else
                std::cout << "[" << i << "] : " << table[i] << "\n";
        }
    }


};

int main () {
    Hash_Table hashTable;

    hashTable.insert(12);
    hashTable.insert(60);
    hashTable.insert(56);
    hashTable.insert(78);
    hashTable.insert(43);
    hashTable.insert(80);
    hashTable.insert(30);
    hashTable.remove(56);
    hashTable.display();
    
    return 0;
}
