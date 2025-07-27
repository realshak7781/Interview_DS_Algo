class Solution {
private:
int getMax(int x,int y,vector<vector<int>>&grid,int n){
    // the 3*3 matrix is centered around x and y
    int startX=x-1;
    int startY=y-1;

    int maxi=grid[x][y];
    for(int i=startX;i<startX+3;i++){
        for(int j=startY;j<startY+3;j++){
            maxi=max(maxi,grid[i][j]);
        }
    }

    return maxi;
}
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> res(n-2,vector<int>(n-2,0));

        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                res[i][j]=getMax(i+1,j+1,grid,n);
            }
        }

        return res;
    }
};
