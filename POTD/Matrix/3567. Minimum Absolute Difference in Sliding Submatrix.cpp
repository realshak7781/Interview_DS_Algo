

// TIME : O(R*C*K^2*LOG(K)))
// SPACE: O(R*C + K^2)
class Solution {
private:
int getMinAbsDiff(int r1,int c1,int r2,int c2,vector<vector<int>>& grid){
    set<int> st;

    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            st.insert(grid[i][j]);
        }
    }

    if(st.size()<2) return 0;

    int prevVal=-1e9;
    int minDiff=INT_MAX;

    for(int val:st){
        if(prevVal!=-1e9){
            minDiff=min(minDiff,abs(val-prevVal));
        }
        prevVal=val;
    }

    return minDiff;
}
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>> res(rows-k+1,vector<int>(cols-k+1,0));

        for(int r=0;r<=(rows-k);r++){
            for(int c=0;c<=(cols-k);c++){
                res[r][c]=getMinAbsDiff(r,c,r+k-1,c+k-1,grid);
            }
        }

        return res;
    }
};
