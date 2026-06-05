#include <iostream>
#include <vector>

using namespace std;

int main() {
    int C;
    cin >> C;      // capacity

    int n;
    cin >> n;      // number of LOG operations

    vector<int> buffer(C);

    int head = 0;        // oldest element
    int size = 0;        // current elements in buffer
    int overwrites = 0;

    for(int i = 0; i < n; i++) {
        string op;
        int id;

        cin >> op >> id;

        // Buffer not full
        if(size < C) {
            int writeSlot = (head + size) % C;

            buffer[writeSlot] = id;
            size++;
        }
            // Buffer full
        else {
            buffer[head] = id;

            head = (head + 1) % C;
            overwrites++;
        }
    }

    cout << "Buffer: ";

    for(int i = 0; i < size; i++) {
        int index = (head + i) % C;
        cout << buffer[index] << " ";
    }

    cout << endl;
    cout << "Overwrites: " << overwrites;

    return 0;
}