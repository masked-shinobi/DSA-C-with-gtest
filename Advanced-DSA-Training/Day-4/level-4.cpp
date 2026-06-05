#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> demand(n);

    for (int i = 0; i < n; i++) {
        cin >> demand[i];
    }

    vector<int> answer(n, 0);
    stack<int> st;   // stores indices

    for (int i = 0; i < n; i++) {

        while (!st.empty() && demand[i] > demand[st.top()]) {

            int topIndex = st.top();
            st.pop();

            answer[topIndex] = i - topIndex;
        }

        st.push(i);
    }

    cout << "Days To Higher: ";

    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}