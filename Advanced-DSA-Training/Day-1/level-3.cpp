#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> revenue(n);

    for (int i = 0; i < n; i++) {
        cin >> revenue[i];
    }

    long long T;
    cin >> T;

    int L = 0;
    long long sum = 0;
    int bestLength = INT_MAX;

    for (int R = 0; R < n; R++) {
        sum += revenue[R];

        while (sum >= T) {
            int currentLength = R - L + 1;
            bestLength = min(bestLength, currentLength);

            sum -= revenue[L];
            L++;
        }
    }

    if (bestLength == INT_MAX) {
        cout << "Shortest Window: 0";
    } else {
        cout << "Shortest Window: " << bestLength;
    }

    return 0;
}