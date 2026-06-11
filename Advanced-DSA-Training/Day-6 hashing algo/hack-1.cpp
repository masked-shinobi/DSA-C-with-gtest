#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PaymentHashMap {
private:
    //
    struct Node {
        string key;
        int value;
        Node* next;

        Node(string k, int v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    vector<Node*> buckets;
    int capacity;
    int currentSize;

    double loadFactor() {
        return (double)currentSize / capacity;
    }

    int hashFunction(string key) {
        long long hash = 0;

        for (char c : key) {
            hash = hash * 31 + c;
        }

        return abs(hash) % capacity;
    }

    void rehash() {
        vector<Node*> oldBuckets = buckets;

        capacity *= 2;
        buckets.clear();
        buckets.resize(capacity, nullptr);

        int oldSize = currentSize;
        currentSize = 0;

        for (Node* head : oldBuckets) {
            Node* curr = head;

            while (curr) {
                put(curr->key, curr->value);

                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }

        currentSize = oldSize;
    }

public:
    PaymentHashMap() {
        capacity = 16;
        currentSize = 0;
        buckets.resize(capacity, nullptr);
    }

    void put(string key, int value) {

        int index = hashFunction(key);

        Node* curr = buckets[index];

        // Update existing key
        while (curr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }

        // Insert at head
        Node* newNode = new Node(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;

        currentSize++;

        if (loadFactor() > 0.75) {
            rehash();
        }
    }

    int get(string key) {
        int index = hashFunction(key);

        Node* curr = buckets[index];

        while (curr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }

        return -1;
    }

    bool containsKey(string key) {
        return get(key) != -1;
    }

    int remove(string key) {
        int index = hashFunction(key);

        Node* curr = buckets[index];
        Node* prev = nullptr;

        while (curr) {

            if (curr->key == key) {

                if (prev == nullptr) {
                    buckets[index] = curr->next;
                }
                else {
                    prev->next = curr->next;
                }

                int val = curr->value;

                delete curr;
                currentSize--;

                return val;
            }

            prev = curr;
            curr = curr->next;
        }

        return -1;
    }

    int size() {
        return currentSize;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    void clear() {

        for (int i = 0; i < capacity; i++) {

            Node* curr = buckets[i];

            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }

            buckets[i] = nullptr;
        }

        currentSize = 0;
    }

    void display() {

        for (int i = 0; i < capacity; i++) {

            cout << "[" << i << "] -> ";

            Node* curr = buckets[i];

            while (curr) {
                cout << "(" << curr->key
                     << "," << curr->value << ") -> ";
                curr = curr->next;
            }

            cout << "NULL\n";
        }
    }

    ~PaymentHashMap() {
        clear();
    }
};

int main() {

    PaymentHashMap map;

    map.put("raj@okhdfc", 1000);
    map.put("sam@oksbi", 2000);
    map.put("alex@okicici", 3000);

    cout << map.get("sam@oksbi") << endl;

    cout << map.containsKey("raj@okhdfc") << endl;

    cout << map.remove("raj@okhdfc") << endl;

    cout << map.size() << endl;

    map.display();

    return 0;
}