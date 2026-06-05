#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> remaining(n);

    for(int i = 0; i < n; i++) {
        cin >> remaining[i];
    }

    queue<int> tasks;

    // store task numbers (indices)
    for(int i = 0; i < n; i++) {
        tasks.push(i);
    }

    vector<int> completionOrder;
    int turns = 0;

    while(!tasks.empty()) {
        int current = tasks.front();
        tasks.pop();

        int run = min(remaining[current], q);

        remaining[current] -= run;
        turns++;

        if(remaining[current] == 0) {
            completionOrder.push_back(current + 1); // 1-based task number
        }
        else {
            tasks.push(current);
        }
    }

    cout << "Completion Order: ";

    for(int task : completionOrder) {
        cout << task << " ";
    }

    cout << endl;
    cout << "Turns: " << turns;

    return 0;
}