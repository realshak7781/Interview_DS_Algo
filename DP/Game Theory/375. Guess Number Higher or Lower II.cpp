
// Using Botom Up approach:
class Solution {
private:

    int bottomUp(int n) {
        // state definition : dp[start][end] : min amount of money to win
        // regardless of what number one chooses in this range
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n; len++) {

            for (int start = 1; start <= (n - len + 1); start++) {
                int end = start + len - 1;

                int minCash = INT_MAX;
                for (int i = start; i <= end; i++) {
                    int leftCash = dp[start][i - 1];
                    int rightCash = dp[i + 1][end];

                    int maxi = max(leftCash, rightCash);
                    minCash = min(minCash, i + maxi);
                }

                dp[start][end]=minCash;
            }
        }

        return dp[1][n];
    }

public:
    int getMoneyAmount(int n) { return bottomUp(n); }
};

// Using Recursion + Memoization
class Solution {
private:
unordered_map<int,unordered_map<int,int>> dp;
int solve(int start,int end){
    if(start==end) return 0;

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
