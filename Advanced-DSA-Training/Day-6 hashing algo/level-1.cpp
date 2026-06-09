// Lab 1 - Custom HashMap with String Keys (separate chaining)
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
struct Node { string key; int value; Node* next; Node(string k,int v,Node*
    n):key(k),value(v),next(n){} };
class MyHashMap {
    int capacity, size;
    vector<Node*> buckets;
    int hashKey(const string& key){
        long long h = 0, p = 31;
        for (char ch : key) h = (h * p + (unsigned char)ch) % capacity;
        return (int)h;
    }
    void rehash(){
        vector<Node*> old = buckets;
        capacity *= 2;
        buckets.assign(capacity, nullptr);
        for (Node* head : old){
            Node* node = head;
            while (node){
                int idx = hashKey(node->key);
                buckets[idx] = new Node(node->key, node->value, buckets[idx]);
                Node* tmp = node; node = node->next; delete tmp;
            }
        }
    }
public:
    MyHashMap(): capacity(16), size(0), buckets(16, nullptr) {}
    void put(const string& key, int value){
        int idx = hashKey(key);
        for (Node* node = buckets[idx]; node; node = node->next)
            if (node->key == key){ node->value = value; return; }
        buckets[idx] = new Node(key, value, buckets[idx]);
        size++;
        if (size * 4 > capacity * 3) rehash();
    }
    int get(const string& key){
        for (Node* node = buckets[hashKey(key)]; node; node = node->next)
            if (node->key == key) return node->value;
        return -1;
    }
    void remove(const string& key){
        int idx = hashKey(key);
        Node* node = buckets[idx]; Node* prev = nullptr;
        while (node){
            if (node->key == key){
                if (prev) prev->next = node->next; else buckets[idx] = node->next;
                delete node; size--; return;
            }
            prev = node; node = node->next;
        }
    }
    int getSize(){ return size; }
    int getCapacity(){ return capacity; }
};
int main(){
    MyHashMap m;
    string line;
    vector<string> out;
    while (getline(cin, line)){
        if (line.empty()) continue;
        istringstream iss(line); string op; iss >> op;
        if (op == "PUT"){ string k; int v; iss >> k >> v; m.put(k, v); }
        else if (op == "GET"){ string k; iss >> k; out.push_back(to_string(m.get(k))); }
        else if (op == "REMOVE"){ string k; iss >> k; m.remove(k); }
    }
    out.push_back("Size: " + to_string(m.getSize()));
    out.push_back("Capacity: " + to_string(m.getCapacity()));
    for (auto& s : out) cout << s << "\n";
    return 0;
}
