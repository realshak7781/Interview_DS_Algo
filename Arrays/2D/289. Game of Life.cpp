// optimal : O(1) space :
class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                                {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

public:
    void gameOfLife(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // if 0 needs to change to 1 we will mark it with  : -2;
        // if 1 needs to change to 0 we will mark it with : -1:

        // essentialyb when checking 8 direction if you get -1 it is taken as 1
        // and if -2 is found taken as 0

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int count = 0;

                for (auto d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                        (grid[ni][nj] == 1 || grid[ni][nj] == -1)) {
                        count++;
                    }
                }

                if (grid[i][j] == 1) {
                    if (count < 2) {
                        grid[i][j] = -1;
                    } else if (count >= 2 && count <= 3) {
                        continue;
                    } else if (count > 3) {
                        grid[i][j] = -1;
                    }
                } else {
                    if (count == 3) {
                        grid[i][j] = -2;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == -1) {
                    grid[i][j] = 0;
                } else if (grid[i][j] == -2) {
                    grid[i][j] = 1;
                }
            }
        }
    }
};




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
