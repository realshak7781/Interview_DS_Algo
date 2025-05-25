#include <iostream>
#include <vector>
#include <unordered_map>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using LL = long long;

bool solveRecur(int opCount, LL cur, unordered_map<LL, bool> &aMap, vector<LL> &sequence, int n) {
    if (opCount == n - 1) {  // Base case: we have found n elements
        sequence.push_back(cur);
        return true;
    }

    aMap[cur] = false;  // Mark as visited
    sequence.push_back(cur);

    // Try dividing by 3 if possible
    if (cur % 3 == 0 && aMap[cur / 3]) {
        if (solveRecur(opCount + 1, cur / 3, aMap, sequence, n)) {
            return true;
        }
    }

    // Try multiplying by 2
    if (aMap[cur * 2]) {
        if (solveRecur(opCount + 1, cur * 2, aMap, sequence, n)) {
            return true;
        }
    }

    // Backtrack: undo last choice
    sequence.pop_back();
    aMap[cur] = true;
    return false;
}

void solve() {
    LL n;
    cin >> n;
    vector<LL> a(n);

    unordered_map<LL, bool> aMap;
    for (auto &it : a) {
        cin >> it;
        aMap[it] = true;
    }

    for (int i = 0; i < n; i++) {
        LL val = a[i];
        vector<LL> sequence;
        bool possible = solveRecur(0, val, aMap, sequence, n);

        if (possible) {
            for (auto &it : sequence) {
                cout << it << " ";
            }
            cout << "\n";
            return;
        }
        aMap[val] = true;  // Restore the value in case we try another sequence
    }
}

int main() {
    FAST_IO;
    int t = 1;
    // cin >> t;  // Uncomment if multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
