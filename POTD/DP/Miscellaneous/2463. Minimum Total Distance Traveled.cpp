

// Using Recursion + Memoization

using ll = long long;
class Solution {
private:
    unordered_map<int,unordered_map<int,ll>> dp;
    ll solve(int i, int j, vector<int>& robot, vector<int>& factoryPos) {
        if (i >= robot.size()) {
            return 0;
        }

        if (j>=factoryPos.size()){
            return LLONG_MAX;
        }

        if(dp[i].count(j)) return dp[i][j];
        // take
        ll take=solve(i+1,j+1,robot,factoryPos);

        if(take!=LLONG_MAX){
            take+=abs(factoryPos[j]-robot[i]);
        }

        ll skip=solve(i,j+1,robot,factoryPos);

        return dp[i][j]=min(take,skip);

    }

public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {

        sort(begin(factory), end(factory));
        sort(begin(robot), end(robot));

        vector<int> factoryPos;

        for (auto& f : factory) {
            int count = f[1];

            while (count > 0) {
                factoryPos.push_back(f[0]);
                count--;
            }
        }


        return solve(0, 0,robot, factoryPos);
    }
};
