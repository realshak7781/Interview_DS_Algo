
// brute force : because of extra Space O(m*n)
class Solution {
private:
vector<vector<int>> dirs={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int checkLive(vector<vector<int>>& grid,int r,int c,int n,int m){
    // count the live neigh
    int count=0;
    for(auto d:dirs){
        int nr=r+d[0];
        int nc=c+d[1];

        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
            count++;
        }
    }

    if(grid[r][c]==1){
        if(count<2){
            return 0;
        }
        else if(count>=2 && count<=3){
            return 1;
        }
        else if(count>3){
            return 0;
        }
    }
    else{
        if(count==3){
            return 1;
        }
        else{
            return 0;
        }
    }

    return -1;
}
public:
    void gameOfLife(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> res;
        res=grid;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // check all directions

                if(grid[i][j]==1){
                    res[i][j]=checkLive(grid,i,j,n,m);
                }
                else{
                    res[i][j]=checkLive(grid,i,j,n,m);
                }
            }
        }



        grid=res;
    }
};
