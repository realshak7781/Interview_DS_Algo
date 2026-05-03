//Python solutiin :
class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort(key=lambda x: x[0])

        factoryPos=[]

        for f in factory:
            count=f[1]

            while count>0:
                factoryPos.append(f[0])
                count-=1
        
        @lru_cache(None)
        def solve(i,j):

            if i>=len(robot):
                return 0
            
            if j>=len(factoryPos):
                return math.inf

            take=solve(i+1,j+1)

            if take!=math.inf:
                take+=abs(robot[i]-factoryPos[j])
            
            skip=solve(i,j+1)

            minDist=min(take,skip)

            return minDist
        
        ans=solve(0,0)
        solve.cache_clear()
        return ans


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
