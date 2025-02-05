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


void buildSegmentTree(int idx,int l,int r,vector<int>&segment,vector<int>&arr){
    if(l==r){
        segment[idx]=arr[l];
        return;
    }

    int mid=l+(r-l)/2;

    buildSegmentTree(2*idx+1,l,mid,segment,arr);
    buildSegmentTree(2*idx+2,mid+1,r,segment,arr);
    segment[idx]=segment[2*idx+1]+segment[2*idx+2];
}


void PointUpdateQuery(int idx,int upIdx,int l,int r,int val,vector<int>&segment){

    if(l==r){
        segment[idx]=val;
        return;
    }
    int mid=l+(r-l)/2;
    if(upIdx<=mid){
        PointUpdateQuery(2*idx+1,upIdx,l,mid,val,segment);
    }
    else{
        PointUpdateQuery(2*idx+2,upIdx,mid+1,r,val,segment);
    }
    segment[idx]=segment[2*idx+1]+segment[2*idx+2];
}



int rangeSumQuery(int idx,int l,int r,vector<int>&segment,int r1,int r2){

    if(r<r1 || l>r2) return 0;

    else if(l>=r1 && r<=r2) return  segment[idx];

    else{
        int mid=l+(r-l)/2;
        return (rangeSumQuery(2*idx+1,l,mid,segment,r1,r2)+rangeSumQuery(2*idx+2,mid+1,r,segment,r1,r2));
    }

    return 0;
}

// lazy is same size as segment array and intialized with 0
void updateRangeQuery(int start,int end,int i,int l,int r,vector<int>&segments,vector<int>&lazy,int val){
    if(lazy[i]!=0){
        segments[i]+=(r-l+1)*lazy[i];
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }

    if(l>r || l>end || r<start) return;

    if(l>=start && r<=end){
        segments[i]+=(r-l+1)*val;
        if(l!=r){
            lazy[2*i+1]+=val;
            lazy[2*i+2]+=val;
        }
        return;
    }

    int mid=l+(r-l)/2;  

    updateRangeQuery(start,end,2*i+1,l,mid,segments,lazy,val);
    updateRangeQuery(start,end,2*i+2,mid+1,r,segments,lazy,val);

    segments[i]=segments[2*i+1]+segments[2*i+2];
}

// Main Function Template
int main() {
    FAST_IO;

    int n;
    cin>>n;
    vector<int> arr(n,0);
    FOR(i, 0, n) {
        cin>>arr[i];
    }

    vector<int>segmentArr(4*n,0);

    buildSegmentTree(0,0,n-1,segmentArr,arr);

    for(auto&it:segmentArr)cout<<it<<"  ";

    cout<<endl;

    // int val;
    // cout<<"Enter your val: "<<endl;
    // cin>>val;

    // updateQuery(0,1,0,n-1,val,segmentArr);

    // for(auto&it:segmentArr)cout<<it<<"  ";

    cout<<"enter your range of range sum query: "<<endl;
    int r1,r2;
    cin>>r1>>r2;

    int rangeSum=rangeSumQuery(0,0,n-1,segmentArr,r1,r2);

    cout<<rangeSum<<endl;
    return 0;
}