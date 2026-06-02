#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    int total = 0;
    //hashmap creation
    unordered_map<string, long long> priceMap;
    // length of the catalog
    int m;
    cin >> m;
    //hashmap build
    for (int i = 0; i < m; i++){
        string id;
        float price;

        cin >> id >> price;

        priceMap[id] = price;
    }
    // cart read

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string id;
        int qty;

        cin >> id >> qty;
        //calculation
        total = total + (priceMap[id] * qty);
    }

    cout<<"Cart Total: "<< total;

    return 0;
}