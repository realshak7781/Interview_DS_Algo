// T.C: O(N)
// S.C: O(1)
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.length();

        //  a better optimised approach
        vector<int> res(26,0);
        for(int i=0;i<n;i++){

            int curOrder=s[i]-'a';
            int left=max(0,curOrder-k);
            int right=min(25,curOrder+k);

            int longest=0;
            for(int j=left;j<=right;j++){
                longest=max(longest,res[j]);
            }

            res[curOrder]=max(longest+1,res[curOrder]);
        }

        int result=*max_element(res.begin(),res.end());

        return result;
    }
};


//RECURSION+MEMO 
// T.C: O(N*26)
//S.C: O(N*26)+O(N)
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
