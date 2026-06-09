// Lab 3 - MyHashMap with Open Addressing (linear probing + tombstones + resizing)
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
static const int EMPTY = -1, TOMB = -2;
class MyHashMap {
    int capacity, size;
    vector<int> keys, values;
    int hashKey(int key){ return key % capacity; }
    int probe(int key, int i){ return (hashKey(key) + i) % capacity; }
    void rehash(){
        vector<int> ok = keys, ov = values;
        capacity *= 2;
        keys.assign(capacity, EMPTY);
        values.assign(capacity, 0);
        size = 0;
        for (size_t j = 0; j < ok.size(); j++)
            if (ok[j] != EMPTY && ok[j] != TOMB) put(ok[j], ov[j]);
    }
public:
    MyHashMap(int cap): capacity(cap), size(0), keys(cap, EMPTY), values(cap, 0) {}
    void put(int key, int value){
        int firstTomb = -1;
        for (int i = 0; i < capacity; i++){
            int idx = probe(key, i);
            if (keys[idx] == EMPTY){
                int slot = (firstTomb != -1) ? firstTomb : idx;
                keys[slot] = key; values[slot] = value; size++;
                if ((double)size / capacity > 0.7) rehash();
                return;
            }
            if (keys[idx] == TOMB){ if (firstTomb == -1) firstTomb = idx; }
            else if (keys[idx] == key){ values[idx] = value; return; }
        }
    }
    int get(int key){
        for (int i = 0; i < capacity; i++){
            int idx = probe(key, i);
            if (keys[idx] == EMPTY) return -1;
            if (keys[idx] == key) return values[idx];
        }
        return -1;
    }
    void remove(int key){
        for (int i = 0; i < capacity; i++){
            int idx = probe(key, i);
            if (keys[idx] == EMPTY) return;
            if (keys[idx] == key){ keys[idx] = TOMB; size--; return; }
        }
    }
    int getSize(){ return size; }
    int getCapacity(){ return capacity; }
};
int main(){
    string line; getline(cin, line);
    int cap = stoi(line);
    MyHashMap m(cap);
    vector<string> out;
    while (getline(cin, line)){
        if (line.empty()) continue;
        istringstream iss(line); string op; iss >> op;
        if (op == "PUT"){ int k, v; iss >> k >> v; m.put(k, v); }
        else if (op == "GET"){ int k; iss >> k; out.push_back(to_string(m.get(k))); }
        else if (op == "REMOVE"){ int k; iss >> k; m.remove(k); }
    }
    out.push_back("Size: " + to_string(m.getSize()));
    out.push_back("Capacity: " + to_string(m.getCapacity()));
    for (auto& x : out) cout << x << "\n";
    return 0;
}