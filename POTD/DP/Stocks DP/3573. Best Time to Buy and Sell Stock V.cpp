

// Recursion + Memoization
using ll=long long;
class Solution {
private:
ll dp[1001][2][3][1000];
ll solve(int idx, bool activeTransaction, int transType, int k, vector<int>& prices) { 
    if (idx >= prices.size()) {
        if(activeTransaction){
            if(transType==1){
                // clsoing the opne short position
                return -1e9;
            }
            // closing the open normal sell position
            return 0;
        }
        return 0;
    }
    
    if (k == 0 && activeTransaction == false) return 0;

    if(dp[idx][activeTransaction][transType][k]!=-1) return dp[idx][activeTransaction][transType][k];
    
    ll res = -1e18; 

    if (activeTransaction) {
        if (transType == 0) {
            // Sell Long
            res = max(res, prices[idx] + solve(idx + 1, false, 2, k, prices));
        }
        else if (transType == 1) {
            // Buy Back Short
            res = max(res, solve(idx + 1, false, 2, k, prices) - prices[idx]);
        }
    }
    else {
        // Buy Long
        res = max(res, solve(idx + 1, true, 0, k - 1, prices) - prices[idx]);
        // Short Sell
        res = max(res, solve(idx + 1, true, 1, k - 1, prices) + prices[idx]);
    }

    res = max(res, solve(idx + 1, activeTransaction, transType, k, prices));

    return dp[idx][activeTransaction][transType][k]=res;
}
public:
    long long maximumProfit(vector<int>& prices, int k) {
        
        memset(dp, -1, sizeof(dp));
        return solve(0,false,2,k,prices);
    }
};
