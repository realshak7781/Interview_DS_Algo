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

void solve() {
    LL n;
    cin >> n;


    LL a = -1, b = -1, c = -1;

    // Find the first prime factor (a)
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a = i;
            n /= i;
            break;
        }
    }

    // If no prime factor found, n is prime, so output "NO"
    if (a == -1) {
        cout << "NO\n";
        return;
    }

    // Find the second prime factor (b)
    for (LL i = a + 1; i * i <= n; i++) {
        if (n % i == 0) {
            b = i;
            n /= i;
            break;
        }
    }

    // The remaining n must be a prime factor and distinct from a and b
    if (n > 1 && n != a && n != b) {
        c = n;
    }

    // Output the result
    if (a != -1 && b != -1 && c != -1) {
        cout << "YES\n" << a << " " << b << " " << c << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    FAST_IO;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}