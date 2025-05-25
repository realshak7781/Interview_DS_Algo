#include <bits/stdc++.h>
using namespace std;

// Macros for convenience
#define LL long long
#define ULL unsigned long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Constants
const LL MOD = 1e9 + 7;
const LL INF = 1e18;
const LD EPS = 1e-9;

// Utility Functions
bool isPerfectSquare(LL n) {
    if (n < 0) return false;
    LL root = sqrt(n);
    return root * root == n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n + 1);

    // Initialize ans[i] = i
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }

    // Edge case: If n=1 or sum 1+2+...+n is a perfect square
    LL totalSum = (1LL * n * (n + 1)) / 2;
    if (isPerfectSquare(totalSum)) {
        cout << "-1\n";
        return;
    }

    // Prefix sum approach
    LL prefixSum = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum += ans[i];

        // If prefixSum is a perfect square, swap adjacent elements
        if (isPerfectSquare(prefixSum)) {
            swap(ans[i], ans[i + 1]);
            prefixSum += ans[i] - ans[i + 1];  // Update prefix sum after swap
        }

        cout << ans[i] << " ";
    }
    cout << "\n";  // Print newline after each test case
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
