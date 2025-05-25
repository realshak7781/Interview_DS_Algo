#include <bits/stdc++.h>
using namespace std;

// Macros for convenience
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;

    vector<int> dp(n, 1), parent(n, -1); 
    map<int, int> elemToInd;  // Using `map` instead of `unordered_map` to avoid worst-case hash collisions

    int maxInd = 0, maxSubLen = 1;

    for (int i = 0; i < n; i++) {
        int it = a[i];

        if (elemToInd.count(it - 1)) {  // Check if the previous element exists
            int prevInd = elemToInd[it - 1];
            dp[i] = dp[prevInd] + 1;
            parent[i] = prevInd;
        }

        elemToInd[it] = i; // Store last occurrence of the current element

        if (dp[i] > maxSubLen) {
            maxSubLen = dp[i];
            maxInd = i;
        }
    }

    // Reconstruct the longest subsequence
    cout << maxSubLen << "\n";
    vector<int> result;
    for (int i = maxInd; i != -1; i = parent[i]) {
        result.push_back(i + 1);  // Convert to 1-based index
    }

    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

int main() {
    FAST_IO;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
