class Solution {
private:
    vector<int> res;
    vector<vector<int>> dp;
    int recur(int idx, int amount, const vector<int>& coins) {
        if (amount == 0)
            return 1;
        if (amount < 0 || idx >= coins.size())
            return 0;
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int take = recur(idx, amount - coins[idx], coins);
        int notTake = recur(idx + 1, amount, coins);
        return dp[idx][amount] = take + notTake;
    }

public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        for (int i = 0; i < n; i++) {
            int amount = i + 1;
            int ways = numWays[i];

           if (ways >=1) {
                // the total Waays to forum cur amount with cur res array
                int n = res.size();
                dp.clear();
                dp.resize(n + 1, vector<int>(amount + 1, -1));
                int totalWays = recur(0, amount,res);
                int remWays = ways - totalWays;

                if (remWays == 1) {
                    res.push_back(amount);
                } else if (remWays!=0) {
                    return {};
                }
            }
            else if(ways==0){
                // ways=0;
                int n = res.size();
                dp.clear();
                dp.resize(n + 1, vector<int>(amount + 1, -1));
                int totalWays = recur(0, amount,res);
                if(totalWays!=0) return {};
            }
        }

        return res;
    }
};
