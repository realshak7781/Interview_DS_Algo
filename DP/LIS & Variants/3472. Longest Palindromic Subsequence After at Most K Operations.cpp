class Solution {
private:
int dp[201][201][201];
int getCost(char a,char b){
    int diff=abs(a-b);
    return min(diff,26-diff);
}
int lps(int left,int right,string &s,int k){
    if(left==right) return 1;
    if(left>right) return 0;

    if(dp[left][right][k]!=-1) return dp[left][right][k];

    int maxLen=0;
    int skip_left=lps(left+1,right,s,k);
    int skip_right=lps(left,right-1,s,k);

    maxLen=max(skip_left,skip_right);

    // try to matcch the character using the k
    int cost = getCost(s[left], s[right]);

    if(cost<=k){
        maxLen=max(maxLen,2+lps(left+1,right-1,s,k-cost));
    }

    return dp[left][right][k]=maxLen;
}
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        return lps(0,n-1,s,k);
    }
};
