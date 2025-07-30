
//Approach-1 (Brute Force)
//T.C : O(n * n!)
//S.C : O(n * n!), storing all permutations in set
class Solution {
public:
    int countBalancedPermutations(string num) {
        sort(begin(num),end(num));
        // sorting helps to generate lexico order of permutations

        unordered_set<string> vis;
        // taking set in case of duplicate permutation in strings like :"1123"
        int count=0;

        do{
            if(vis.count(num)) continue;

            vis.insert(num);
            int evnSum=0,odSum=0;

            for(int i=0;i<num.length();i++){
                int dig=num[i]-'0';
                if(i&1){
                    odSum+=dig;
                }
                else{
                    evnSum+=dig;
                }
            }
            if(evnSum==odSum) count++;
        }
        while(next_permutation(begin(num),end(num)));


        return count;
    }
};


//Approach-2 (Recursion + Memoization)
//T.C : O(10 * n^2 * Sum)
//S.C : O(10 ^ n * Sum)
using ll=long long;
class Solution {
private:
int n;
int totalDigSum;
const int mod=1e9+7;
ll totalPermPossible=0;
vector<vector<vector<int>>> dp;
int findPower(ll a ,ll b){
    if(b==0)return 1;

    ll half=findPower(a,b/2);

    ll result=(half*half)%mod;

    if(b&1){
        result=(result*a)%mod;
    }

    return result;
}

int solve(int digit,int evenIdxDigCount,int curSum,vector<int>&freq,vector<ll>&invFact){
    if(digit==10){
        if(curSum==(totalDigSum/2) && evenIdxDigCount==(n+1)/2){
            return totalPermPossible;
        }
        return 0;
    }

    if(dp[digit][evenIdxDigCount][curSum]!=-1) return dp[digit][evenIdxDigCount][curSum];

    ll ways=0;
    for(int count=0;count<=min(freq[digit],((n+1)/2)-evenIdxDigCount);count++){
        int evenPosCount=count;
        int oddPosCount=freq[digit]-count;

        ll div=(invFact[evenPosCount]*invFact[oddPosCount])%mod;

        ll val=solve(digit+1,evenIdxDigCount+evenPosCount,curSum+digit*count,freq,invFact);

        ways=(ways+(val*div)%mod)%mod;
    }

    return dp[digit][evenIdxDigCount][curSum]=ways;
}
public:
    int countBalancedPermutations(string num) {
        n=num.length();
        totalDigSum=0;
        vector<int> freq(10,0);
        for(int i=0;i<n;i++){
            freq[num[i]-'0']++;
            totalDigSum+=(num[i]-'0');
        }

        if((totalDigSum%2)!=0){
            return 0;
        }
        // precompute factorials;
        vector<ll> fact(n+1,1);
        fact[0]=1;
        fact[1]=1;

        for(int i=2;i<=n;i++){
            fact[i]=(1LL*fact[i-1]*i)%mod;
        }

        // precompute inv Factorial ; (1/x!)%mod
        // using fermat little theorem

        vector<ll> invFact(n+1,0);
        for(int i=0;i<=n;i++){
            invFact[i]=findPower(fact[i],mod-2)%mod;
        }

        totalPermPossible= (1LL * fact[(n+1)/2] * fact[n/2] )%mod;
        int evenIdxDigCount=0;

        dp= vector<vector<vector<int>>> (10,vector<vector<int>>( (n+1)/2 +1,vector<int>(totalDigSum+1,-1)));
        return solve(0,evenIdxDigCount,0,freq,invFact);
    }
};
