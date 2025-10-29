

// Using Recursion + Memoization
class Solution {
private:
unordered_map<int,unordered_map<int,int>> dp;
int solve(int start,int end){
    if(start==end) return 0;
    if(start>end) return INT_MIN;

    if(dp[start].count(end)) return dp[start][end];
    int minCash=INT_MAX;

    for(int i=start;i<=end;i++){
        int leftCash=solve(start,i-1);
        int rightCash=solve(i+1,end);

        int maxi=max(leftCash,rightCash);
        minCash=min(minCash,i+maxi);
    }

    return dp[start][end]=minCash;
}
public:
    int getMoneyAmount(int n) {
        return solve(1,n);
    }
};
