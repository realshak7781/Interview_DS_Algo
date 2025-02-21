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


int findCount(vector<int>&a,int val){
    int ans=INT_MIN;

    int low=0,high=a.size()-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(a[mid]<=val){
            ans=max(ans,mid+1);
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

void solve() {
    LL n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);

    for(auto &it:a) cin>>it;
    for(auto &it:b) cin>>it;

    sort(a.begin(),a.end());

    for(auto &val:b){
        int countOfSmall=findCount(a,val);
        cout<<(countOfSmall==INT_MIN?0:countOfSmall)<<" ";
    }
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