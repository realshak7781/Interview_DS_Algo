#include <bits/stdc++.h>
using namespace std;

// Macros for convenience
#define LL long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    LL n;
    cin >> n;
    
    vector<LL> a(n);
    for (auto &it : a) cin >> it;

    vector<LL> posSum(n, 0);
    vector<LL> negSum(n, 0);

    LL pos = 0, neg = 0;

    // Compute prefix sum of positive numbers and suffix sum of negative numbers
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            pos += a[i];
        } else {
            neg += abs(a[i]); // Store absolute sum of negative numbers
        }
        posSum[i] = pos;
        negSum[i] = neg;
    }

    LL ans = max(pos, neg); // Consider full prefix or full suffix
    for (LL i = 0; i < n; i++) {
        ans = max(ans, posSum[i] + neg - negSum[i]);
    }
    
    cout << ans << endl;
}

int main() {
    FAST_IO;
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
