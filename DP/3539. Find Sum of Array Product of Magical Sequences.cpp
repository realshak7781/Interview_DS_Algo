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
