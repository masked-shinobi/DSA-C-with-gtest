#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
// vector values  input
    vector<pair<string, int>> products;

    for(int i = 0; i < n; i++) {
        string id;
        int sales;

        cin >> id >> sales;

        products.push_back({id, sales});
    }

    int k;
    cin >> k;
// priority queue
    priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
    > pq;
// vector to heap
    for(auto &p : products) {

        string id = p.first;
        int sales = p.second;

        if(pq.size() < k) {
            pq.push({sales, id});
        }
        else {

            auto worst = pq.top();

            bool better = false;

            if(sales > worst.first)
                better = true;

            else if(sales == worst.first &&
                    id < worst.second)
                better = true;

            if(better) {
                pq.pop();
                pq.push({sales, id});
            }
        }
    }

    vector<pair<int,string>> ans;

    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }

    sort(ans.begin(), ans.end(),
         [](auto &a, auto &b){

             if(a.first != b.first)
                 return a.first > b.first;   // sales descending

             return a.second < b.second;     // id ascending
         });

    for(auto &x : ans) {
        cout << x.second << " " << x.first << "\n";
    }

    return 0;
}