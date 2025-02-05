#include <bits\stdc++.h>
using namespace std;

// Aliases for commonly used types
using ll = long long;
using ld = long double;
using ull = unsigned long long;

// Macros for convenience
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;

// Directions (for grid problems)
const int dx[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
const int dy[] = {0, 1, 0, -1};

// Debugging utility
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

// Utility functions
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Main driver function
int main() {
    fast_io;

    int t;
    cin >> t; 
    while (t--) {
      int n,a,b;
      cin>>n>>a>>b;
      int aMove;
      int bMove;
    
   while(abs(a-b)>=1){
     if(a>b){
        aMove=a-1;
        bMove=b+1;

        if(aMove==b){
            aMove=a+1;
            if(aMove>n){
                cout<<"NO"<<"\n";
                break;
            }
        }
        a=aMove;
        if(bMove>n||bMove==a){
            bMove=b-1;
            if(bMove<1){
                cout<<"YES"<<"\n";
                break;
            }
        }
        b=bMove;
    }
    else{
        aMove=a+1;
        bMove=b-1;

       
       if(aMove>n||aMove==b){
        aMove=a-1;
        if(aMove<1){
            cout<<"NO"<<"\n";
            break;
        }
       }
       a=aMove;

       if(bMove<1 || bMove==a){
        bMove=b+1;
        if(bMove>n){
            cout<<"YES"<<"\n";
            break;
        }
    }
    b=bMove;
       
}
   
   }
      
   
}
 return 0;
}