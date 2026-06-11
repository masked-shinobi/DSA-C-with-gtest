#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>

using namespace std;

int main() {
    string txnId, userId, recipient;
    long long amount;
    int timestamp;

    // Alert counts
    int duplicateCount = 0;
    int rateLimitCount = 0;
    int moneyMuleCount = 0;
    int structuringCount = 0;

    // DUPLICATE
    unordered_map<string, int> txnSeen;

    // RATE_LIMIT
    unordered_map<string, deque<int>> rateWindow;

    // MONEY_MULE
    unordered_map<string, deque<pair<int, string>>> recipientWindow;

    // STRUCTURING
    unordered_map<string, deque<int>> structWindow;

    while (cin >> txnId >> userId >> recipient >> amount >> timestamp) {

        // =========================
        // 1. DUPLICATE
        // =========================
        if (txnSeen.count(txnId) &&
            timestamp - txnSeen[txnId] <= 5) {

            cout << "DUPLICATE " << txnId << '\n';
            duplicateCount++;
        }

        txnSeen[txnId] = timestamp;

        // =========================
        // 2. RATE_LIMIT
        // =========================
        auto &rateDQ = rateWindow[userId];

        while (!rateDQ.empty() &&
               timestamp - rateDQ.front() > 60) {
            rateDQ.pop_front();
        }

        rateDQ.push_back(timestamp);

        if (rateDQ.size() > 20) {
            cout << "RATE_LIMIT " << txnId << '\n';
            rateLimitCount++;
        }

        // =========================
        // 3. MONEY_MULE
        // =========================
        auto &muleDQ = recipientWindow[userId];

        while (!muleDQ.empty() &&
               timestamp - muleDQ.front().first > 3600) {
            muleDQ.pop_front();
        }

        muleDQ.push_back({timestamp, recipient});

        unordered_set<string> uniqueRecipients;

        for (auto &entry : muleDQ) {
            uniqueRecipients.insert(entry.second);
        }

        if (uniqueRecipients.size() > 50) {
            cout << "MONEY_MULE " << txnId << '\n';
            moneyMuleCount++;
        }

        // =========================
        // 4. STRUCTURING
        // =========================
        auto &structDQ = structWindow[userId];

        while (!structDQ.empty() &&
               timestamp - structDQ.front() > 1800) {
            structDQ.pop_front();
        }

        if (amount < 50000) {
            structDQ.push_back(timestamp);
        }

        if (structDQ.size() >= 10) {
            cout << "STRUCTURING " << txnId << '\n';
            structuringCount++;
        }
    }

    cout << "Duplicate Alerts: " << duplicateCount << '\n';
    cout << "Rate Limit Alerts: " << rateLimitCount << '\n';
    cout << "Money Mule Alerts: " << moneyMuleCount << '\n';
    cout << "Structuring Alerts: " << structuringCount << '\n';

    return 0;
}