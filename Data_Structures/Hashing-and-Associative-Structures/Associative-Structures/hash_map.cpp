/*
    1. Intuitive Explanation

Imagine you have a magical notebook where you can write down a person's name on 
the left and their phone number on the right. 
Whenever you want to find someone's number, 
you simply look up their name and flip directly to the page.
A hash map (or dictionary, associative array) works similarly: 
it stores pairs of "key" → "value" so you can retrieve a value instantly by its key.

Keys: unique identifiers (e.g., names).

Values: data associated (e.g., phone numbers).

Hash function: the magical formula that converts a key into a page number (an array index).

The magic: ideally, the hash function sends you straight to the right spot in constant time, O(1).Z

------------------------------------------------------------------------------------------------------

    2. Real-World Use Cases

Databases & Caches: quick lookup of records by key.

Compilers & Interpreters: symbol tables mapping variable names to memory addresses.

Routing Tables in networks: map IP addresses to next-hop information.

Counting Frequencies: tally occurrences of words, events, etc.

LRU Caches: combine a hash map + linked list for O(1) access & eviction.

----------------------------------------------------------------------------------------------------------
    3. How It Works: Step-by-Step

Initialization: allocate an array (buckets) of size N.

Hashing: apply hash(key) → integer → mod N to get an index.

Insertion:

  Compute index.

  If bucket is empty, place (key, value).

  If collision (another key present), handle via chaining (linked list) or open addressing.

Lookup:

  Compute index.

  Scan chain or probe sequence to find matching key.

Deletion:

  Locate entry.

  Remove it, adjust chain or marking tombstone for open addressing.

Resizing: when load factor (size/N) exceeds threshold (e.g. 0.75), allocate a larger array and rehash all entries.
*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdexcept>

template<typename K, typename V>
class HashMap {
private:
    static const size_t INITIAL_BUCKET_COUNT = 16;
    std::vector<std::list<std::pair<K, V>>> buckets;
    size_t numElements;

    size_t hashKey(const K& key, size_t mod) const {
        return std::hash<K>{}(key) % mod;
    }

    void rehash() {
        size_t newBucketCount = buckets.size() * 2;
        std::vector<std::list<std::pair<K, V>>> newBuckets(newBucketCount);

        for (const auto &bucket : buckets) {
            for (const auto &kv : bucket) {
                size_t idx = hashKey(kv.first, newBucketCount);
                newBuckets[idx].emplace_back(kv);
            }
        }

        buckets.swap(newBuckets);
    }

public:
    HashMap() : buckets(INITIAL_BUCKET_COUNT), numElements(0) {}

    void insert(const K& key, const V& value) {
        if ((numElements + 1.0) / buckets.size() > 0.75) {
            rehash();
        }

        size_t idx = hashKey(key, buckets.size());
        for (auto &kv : buckets[idx]) {
            if (kv.first == key) {
                kv.second = value; // Overwrite
                return;
            }
        }

        buckets[idx].emplace_back(key, value);
        numElements++;
    }

    V get(const K& key) const {
        size_t idx = hashKey(key, buckets.size());
        for (const auto &kv : buckets[idx]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    bool contains(const K& key) const {
        size_t idx = hashKey(key, buckets.size());
        for (const auto &kv : buckets[idx]) {
            if (kv.first == key) {
                return true;
            }
        }
        return false;
    }

    void erase(const K& key) {
        size_t idx = hashKey(key, buckets.size());
        auto &bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                numElements--;
                return;
            }
        }
    }

    size_t size() const { return numElements; }
};


int main() {
    HashMap<std::string, int> map;

    // Insert test
    map.insert("apple", 3);
    map.insert("banana", 5);
    map.insert("orange", 2);

    std::cout << "apple → " << map.get("apple") << "\n";
    std::cout << "banana present? " << (map.contains("banana") ? "yes" : "no") << "\n";

    // Delete test
    map.erase("orange");
    std::cout << "size after erase: " << map.size() << "\n";

    try {
        map.get("orange");
    } catch (const std::out_of_range &e) {
        std::cout << "Correctly threw for missing key 'orange'\n";
    }

    // Overwrite test
    map.insert("apple", 10);
    std::cout << "apple updated → " << map.get("apple") << "\n";

    return 0;
}
