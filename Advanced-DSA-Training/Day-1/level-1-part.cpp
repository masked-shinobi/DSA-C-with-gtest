#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int total = 0;

    int k;
    cin >> k;

    unordered_map<string, int> hash;

    for(int i=0; i < k; i++){
        string id;
        int price;

        cin >> id >> price;
        hash[id] = price;
    }
    int n;
    cin >>n;
    for(int i = 0; i < n; i++){
        string id;
        int qty;

        cin >> id >> qty;

        total = total + (hash[id] * qty);
    }
    cout<<total;
    return 0;
}

