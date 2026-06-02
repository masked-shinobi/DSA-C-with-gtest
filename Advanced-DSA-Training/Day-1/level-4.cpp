#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long K;
    cin >> K;

    unordered_map<long long, long long> freq;

    long long prefixSum = 0;
    long long count = 0;

    // Important: empty prefix
    freq[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        long long need = prefixSum - K;

        if (freq.find(need) != freq.end()) {
            count += freq[
                    need];
        }

        freq[prefixSum]++;
    }

    cout << "Matching Segments: " << count << endl;

    return 0;
}