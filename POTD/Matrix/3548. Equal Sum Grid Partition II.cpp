using ll=long long;
class Solution {
private:
ll totalSum;

bool checkHorCut(vector<vector<int>>& grid){
    int rows=grid.size();
    int cols=grid[0].size();

    unordered_set<ll> seen;
    ll topSum=0;

    for(int i=0;i<=(rows-2);i++){
        for(int j=0;j<cols;j++){
            topSum+=grid[i][j];
            seen.insert(grid[i][j]);
        }

        ll botSum=totalSum-topSum;
        ll diff=topSum-botSum;

        // cut done
        // now check for cut

        if(diff==0) return true;

        if(i==0 && seen.count(diff) && (diff==grid[0][0] || diff==grid[0][cols-1])) return true;

        // if(i>0 && seen.count(diff) && cols==1 && (grid[0][0]==diff || grid[i][0]==diff)) return true;
        // the condition is rewritten below in a clean format
        if(i>0 && seen.count(diff)){
            if(cols>1) return true;

            // cols==1
            if(grid[0][0]==diff || grid[i][0]==diff) return true;
        }
    }

    return false;
}



vector<vector<int>> transpose(vector<vector<int>>& grid){
    int rows=grid.size();
    int cols=grid[0].size();

    vector<vector<int>> res(cols,vector<int>(rows,0));

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            res[j][i]=grid[i][j];
        }
    }
    return res;
}
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        totalSum=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                totalSum+=grid[i][j];
            }
        }

        if(checkHorCut(grid)) return true;

        reverse(begin(grid),end(grid));

        if(checkHorCut(grid)) return true;

        reverse(begin(grid),end(grid));

        vector<vector<int>> transposedGrid=transpose(grid);

        if(checkHorCut(transposedGrid)) return true;

        reverse(begin(transposedGrid),end(transposedGrid));

        if(checkHorCut(transposedGrid)) return true;
        
        return false;
    }
};
