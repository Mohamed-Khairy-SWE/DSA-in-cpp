/*
    Direct Hashing :

    is a straightforward hashing technique where each key
    is directly mapped to a slot in a hash table without any
    complex hash function, the index is derived directly from
    the key itself. This method is efficient when the range
    of keys is small and predictable.
*/

/*
     Static Hashing:

     is a more general approach to hashing where the size of the hash table is
   fixed, and a hash function is used to map keys to table indices.

    Direct Hashing:

    is a specific type of hashing where keys are directly used as indices (e.g.,
   integer keys), often without needing further processing, and it's m    ost
   efficient for cases where keys are inherently indexable.

*/

#include <iostream>
#include <vector>

using namespace std;

class Direct_Hashing {
    private:
        vector<int> table;
        int Maxsize;

    public:
        Direct_Hashing(int maxsize)
            : Maxsize(maxsize) {
            table.resize(maxsize, -1); // Initialize the vector with -1
                                       // (indicating that it's empty)
        }

        void Insert(int key, int value) {
            if (key < 0 || key >= Maxsize) {
                throw("key out of bound!");
            }
            table[key] = value;
        }

        int search(int key) {
            if (key < 0 || key >= Maxsize)
                throw("key out of bound!");
            if (table[key] == -1)
                throw("key not found!");

            return table[key];
        }

        void remove(int key) {
            if (key < 0 || key >= Maxsize) {
                throw("key out of bound!");
            }

            table[key] = -1;
        }

        void display() {
            for (int i = 0; i < Maxsize; i++) {
                if (table[i] != -1)
                    cout << "Key: " << i << " Value: " << table[i] << "\n";
            }
        }
};

int main() {
    Direct_Hashing directhash(9);
    directhash.Insert(3, 30);
    directhash.Insert(5, 50);
    directhash.Insert(7, 70);
    directhash.Insert(8, 80);
    directhash.Insert(1, 90);

    cout << directhash.search(5) << "\n";

    directhash.display();

    directhash.remove(8);

    directhash.display();

    return 0;
}
