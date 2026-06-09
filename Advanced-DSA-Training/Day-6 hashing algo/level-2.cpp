// Lab 2 - MyHashSet with Open Addressing (linear probing + tombstones)
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
static const int EMPTY = -1, TOMB = -2;
class MyHashSet {
    int capacity, size;
    vector<int> table;
    int hashKey(int key){ return key % capacity; }
    int probe(int key, int i){ return (hashKey(key) + i) % capacity; }
    void rehash(){
        vector<int> old = table;
        capacity *= 2;
        table.assign(capacity, EMPTY);
        size = 0;
        for (int v : old) if (v != EMPTY && v != TOMB) add(v);
    }
public:
    MyHashSet(int cap): capacity(cap), size(0), table(cap, EMPTY) {}
    void add(int key){
        int firstTomb = -1;
        for (int i = 0; i < capacity; i++){
            int idx = probe(key, i);
            if (table[idx] == EMPTY){
                int slot = (firstTomb != -1) ? firstTomb : idx;
                table[slot] = key; size++;
                if ((double)size / capacity > 0.7) rehash();
                return;
            }
            if (table[idx] == TOMB){ if (firstTomb == -1) firstTomb = idx; }
            else if (table[idx] == key) return;
        }
    }
    bool contains(int key){
        for (int i = 0; i < capacity; i++){
            int idx = probe(key, i);
            if (table[idx] == EMPTY) return false;
            if (table[idx] == key) return true;
        }
        return false;
    }
    void remove(int key){
        for (int i = 0; i < capacity; i++){
            int idx = probe(key, i);
            if (table[idx] == EMPTY) return;
            if (table[idx] == key){ table[idx] = TOMB; size--; return; }
        }
    }
    int getSize(){ return size; }
    int getCapacity(){ return capacity; }
};
int main() {
    string line;
    getline(cin, line);
    int cap = stoi(line);
    MyHashSet s(cap);
    vector<string> out;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string op;
        int k;
        iss >> op >> k;
        if (op == "ADD") s.add(k);
        else if (op == "CONTAINS") out.push_back(s.contains(k) ? "true" : "false");
        else if (op == "REMOVE") s.remove(k);
    }
    out.push_back("Size: " + to_string(s.getSize()));
    out.push_back("Capacity: " + to_string(s.getCapacity()));
    for (auto &x: out) cout << x << "\n";
    return 0;
}