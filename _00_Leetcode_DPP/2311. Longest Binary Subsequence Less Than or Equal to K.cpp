
// RECURSION + MEMO : TLE
using ll=long long;
class Solution {
private:
int n;
unordered_map<ll,int> dp[1001];
int lis(int idx,ll num,string &s,int k){
    if(idx>=n){
        return 0;
    }

    if(dp[idx].count(num)) return dp[idx][num];

    int notPick=0+lis(idx+1,num,s,k);

    int bit=s[idx]-'0';
    ll curNo=(num<<1)|bit;

    int pick=0;
    if(curNo<=k){
        pick=1+lis(idx+1,curNo,s,k);
    }

    return dp[idx][num]=max(pick,notPick);
}    
public:
    int longestSubsequence(string s, int k) {
        n=s.length();
        return lis(0,0,s,k);
    }
};
