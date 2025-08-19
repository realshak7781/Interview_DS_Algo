class Solution {
private:
    vector<vector<int>> dp;
    int solve(int idx, bool buy, vector<int>& prices) {
        if (idx >= prices.size()) {
            return 0;
        }

        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        int res = 0;
        if (buy) {
            res = max({res, solve(idx + 1, false, prices) - prices[idx],
                       solve(idx + 1, true, prices)});
        } else {
            res = max({res, solve(idx + 1, false, prices), prices[idx]});
        }

        return dp[idx][buy] = res;
    }

    int tab(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int idx = n - 1; idx>= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                int res = 0;
                if (buy) {
                    res = max({res, dp[idx+1][false] - prices[idx],
                               dp[idx + 1][true]});
                } else {
                    res =
                        max({res,dp[idx+1][false], prices[idx]});
                }

                dp[idx][buy] = res;
            }
        }

        return dp[0][1];
    }

public:
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // dp=vector<vector<int>> (n+1,vector<int>(2,-1));
        // return solve(0,true,prices);

        return tab(prices);
    }
};
