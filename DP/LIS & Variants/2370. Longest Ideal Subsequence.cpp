


//RECURSION+MEMO 
// T.C: O(N*26)
//S.C: O(N*26)
class Solution {
private:
int n;
vector<vector<int>> dp;
int solve(int idx,int prevOrder,string &s,int k){
    if(idx>=n){
        return 0;
    }

    if(dp[idx][prevOrder+1]!=-1) return dp[idx][prevOrder+1];

    int notPick=0+solve(idx+1,prevOrder,s,k);
    int curOrder=s[idx]-'a';

    int pick=0;
    if(prevOrder==-1 || (abs(curOrder-prevOrder)<=k)){
        pick=1+solve(idx+1,curOrder,s,k);
    }

    return dp[idx][prevOrder+1]=max(pick,notPick);
}    
public:
    int longestIdealString(string s, int k) {
        n=s.length();
        dp=vector<vector<int>>(n+1,vector<int>(27,-1));
        return solve(0,-1,s,k);
    }
};
