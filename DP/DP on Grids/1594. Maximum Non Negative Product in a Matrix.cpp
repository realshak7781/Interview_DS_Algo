const int mod=1e9+7;
using ll=long long;
using p=pair<ll,ll>;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==0) return 0;

        dp.resize(m,vector<p>(n,{LLONG_MIN, LLONG_MAX}));
        p r=recur(0,0,m,n,grid);
        auto [maxProd,minProd]=recur(0,0,m,n,grid);


        if(maxProd<0)return -1;

        return maxProd%mod;
    }
    private:
    vector<vector<p>> dp;
    p recur(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(i==m-1 && j==n-1){
            return {grid[i][j],grid[i][j]};
        }

        if(dp[i][j]!=make_pair(LLONG_MIN, LLONG_MAX)) return dp[i][j];

        ll maxVal=LLONG_MIN;
        ll minVal=LLONG_MAX;
        ll cur=grid[i][j];

        if(i+1<m){
            auto [downMax,downMin]=recur(i+1,j,m,n,grid);
            maxVal=max({cur*downMax,cur*downMin,maxVal});
            minVal=min({minVal,cur*downMin,cur*downMax});
        }

        if(j+1<n){
            auto [rightMax,rightMin]=recur(i,j+1,m,n,grid);
            maxVal=max({cur*rightMax,cur*rightMin,maxVal});
            minVal=min({minVal,cur*rightMin,cur*rightMax});
        }

        return dp[i][j]={maxVal,minVal};

    }
};
