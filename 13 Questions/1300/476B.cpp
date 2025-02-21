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
LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

LL modAdd(LL a, LL b, LL m = MOD) {
    return ((a % m + b % m) % m + m) % m;
}

LL modSub(LL a, LL b, LL m = MOD) {
    return ((a % m - b % m) % m + m) % m;
}

LL modMul(LL a, LL b, LL m = MOD) {
    return ((a % m) * (b % m)) % m;
}

LL modPow(LL a, LL b, LL m = MOD) {
    LL res = 1;
    while (b > 0) {
        if (b & 1) res = modMul(res, a, m);
        a = modMul(a, a, m);
        b >>= 1;
    }
    return res;
}

LL modInv(LL a, LL m = MOD) {
    return modPow(a, m - 2, m); // m must be prime
}

int findWays(int i, string &s2, int targetSum, int curSum, vector<vector<int>> &dp, int offset) {
    if (i == s2.length()) {
        return (curSum == targetSum) ? 1 : 0;
    }

    if (dp[i][curSum + offset] != -1) return dp[i][curSum + offset];

    if (s2[i] == '?') {
        return dp[i][curSum + offset] = findWays(i + 1, s2, targetSum, curSum + 1, dp, offset) + 
                                       findWays(i + 1, s2, targetSum, curSum - 1, dp, offset);
    } else {
        return dp[i][curSum + offset] = findWays(i + 1, s2, targetSum, curSum + (s2[i] == '+' ? 1 : -1), dp, offset);
    }
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int targetSum = 0;
    for (char c : s1) {
        targetSum += (c == '+' ? 1 : -1);
    }

    int count = std::count(s2.begin(), s2.end(), '?');
    int totalWays = (1 << count); // 2^count

    double probability;
    if (count != 0) {
        int offset = n; // To handle negative indices
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, -1));
        int ways = findWays(0, s2, targetSum, 0, dp, offset);
        probability = (double)ways / totalWays;
    } else {
        int curSum = 0;
        for (char c : s2) {
            curSum += (c == '+' ? 1 : -1);
        }
        probability = (curSum == targetSum) ? 1.0 : 0.0;
    }

    cout << fixed << setprecision(10) << probability << "\n";
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