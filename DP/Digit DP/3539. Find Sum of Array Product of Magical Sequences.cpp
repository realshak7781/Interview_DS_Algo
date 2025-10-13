// Using Recursion + Memoization + Digit DP
using ll=long long;
class Solution {
private:
int N;
const int mod=1e9+7;

map<tuple<ll,int,int,int>,ll> dp;
vector<ll> fact,invFact;

ll findPow(ll a, ll b){
    if(b==0) return 1;

    ll half=findPow(a,b/2);
    ll result= (half*half)%mod;

    if(b&1){
        result = (result*a)%mod;
    }

    return result;
}

// function to calculate the nCr %mod
ll nCr(int n,int r){
    if(r>n) return 0;

    return ((fact[n]*invFact[r])%mod * invFact[n-r])%mod;
}

ll solve(ll binarySum,int idx,int m,int k,vector<int>&nums){


    auto key=make_tuple(binarySum,idx,m,k);
    if(dp.count(key)) return dp[key];

    // base cases
    if(m==0 && __builtin_popcountll(binarySum)==k){
        return 1;
    }


    if(m==0 || idx>=N) return 0;

    ll totalSum=0;

    // skip the current index;
    totalSum= (totalSum+solve(binarySum>>1,idx+1,m,k-(binarySum&1),nums))%mod;

    for(int freq=1;freq<=m;freq++){
        ll newBinarySum=binarySum+freq;

        ll prod=solve(newBinarySum>>1,idx+1,m-freq,k-(newBinarySum&1),nums)%mod;
        prod=(findPow(nums[idx],freq)%mod * prod)%mod;
        prod=(nCr(m,freq)%mod * prod)%mod;
        totalSum=(totalSum+prod)%mod;
    }

    return dp[key]=totalSum%mod;
}
public:
    int magicalSum(int m, int k, vector<int>& nums) {

        N=nums.size();
        // Precomoute Factorials;
        fact.resize(m+1,1);
        invFact.resize(m+1,1);

        for(int i=2;i<=m;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }

        for(int i=0;i<=m;i++){
            invFact[i]=(findPow(fact[i],mod-2))%mod;
        }


        return (int)(solve(0,0,m,k,nums)%mod);
    }
};



// Recursion + Memoization
using ll=long long;
class Solution {
private:
const int mod=1e9+7;
int N,M,K;
unordered_map<string,ll> dp;
ll solve(int count,ll sum,vector<int>&nums){
    if(count==M){
        if(__builtin_popcountll(sum)==K){
            return 1;
        }
        return 0;
    }

    string key=to_string(count)+"_"+to_string(sum);
    if(dp.count(key)) return dp[key];

    ll totalSum=0;
    for(int i=0;i<N;i++){
        ll newSum=sum+ (1LL<<i);

        ll prod=(nums[i]*solve(count+1,newSum,nums))%mod;

        totalSum= (totalSum+prod)%mod;
    }

    return dp[key]=totalSum%mod;
}
public:
    int magicalSum(int m, int k, vector<int>& nums) {

        N=nums.size();
        M=m;
        K=k;
        return (int)(solve(0,0,nums)%mod);
    }
};



// Recursion
using ll=long long;
class Solution {
private:
const int mod=1e9+7;
int N,M,K;

ll solve(int count,ll sum,vector<int>&nums){
    if(count==M){
        if(__builtin_popcountll(sum)==K){
            return 1;
        }
        return 0;
    }

    ll totalSum=0;
    for(int i=0;i<N;i++){
        ll newSum=sum+ (1LL<<i);

        ll prod=(nums[i]*solve(count+1,newSum,nums))%mod;

        totalSum= (totalSum+prod)%mod;
    }

    return totalSum;
}
public:
    int magicalSum(int m, int k, vector<int>& nums) {

        N=nums.size();
        M=m;
        K=k;
        return (int)(solve(0,0,nums)%mod);
    }
};
