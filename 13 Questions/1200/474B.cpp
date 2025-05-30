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


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &it:a) cin>>it;

    vector<pair<int,int>> range;
    for(int i=0;i<n;i++){
        if(i==0){
            range.push_back({1,a[i]});
        }
        else{
            range.push_back({range[i-1].second+1,range[i-1].second+a[i]});
        }
    }

    // for(auto &it:range){
    //     cout<<it.first<<"  "<<it.second<<"\n";
    // }
    
    int m;
    cin>>m;
    vector<int> mArr(m);
    for(auto &it:mArr) cin>>it;
    for(int i=0;i<m;i++){
        int val=mArr[i];
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(val>=range[mid].first && val<=range[mid].second){
                cout<<mid+1<<"\n";
                break;
            }
            else if(val<=range[mid].first) high=mid-1;

            else low=mid+1;
        }
    }
}
// Main Function Template
int main() {
    FAST_IO;

    int t=1;
    // cin >> t; // Input number of test cases
    while (t--) {
        solve();
    }

    return 0;
}