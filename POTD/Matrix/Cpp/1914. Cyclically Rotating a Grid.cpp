class Solution {
private:
void updateGrid(int sr,int er,int sc,int ec,vector<vector<int>>& grid, int k){
    vector<int> temp;
    // push first row
    for(int j=sc;j<=ec;j++){
        temp.push_back(grid[sr][j]);
    }
    // push last col
    for(int i=sr+1;i<=er;i++){
        temp.push_back(grid[i][ec]);
    }

    // push last row
    for(int j=ec-1;j>=sc;j--){
        temp.push_back(grid[er][j]);
    }

    // pushing starrting col
    for(int i=er-1;i>sr;i--){
        temp.push_back(grid[i][sc]);
    }

    int n=temp.size();
    vector<int> rotatedTemp(n);

    k=k%n;
    for(int i=0;i<n;i++){
        int rotIdx=(i-k+n)%n;
        rotatedTemp[rotIdx]=temp[i];
    }

    // now populate back into grid
    int rotIdx=0;

        // push first row
    for(int j=sc;j<=ec;j++){
        grid[sr][j]=rotatedTemp[rotIdx++];
    }
    // push last col
    for(int i=sr+1;i<=er;i++){
        grid[i][ec]=rotatedTemp[rotIdx++];
    }

    // push last row
    for(int j=ec-1;j>=sc;j--){
        grid[er][j]=rotatedTemp[rotIdx++];
    }

    // pushing starrting col
    for(int i=er-1;i>sr;i--){
        grid[i][sc]=rotatedTemp[rotIdx++];
    }
}
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        int sr=0,er=m-1;
        int sc=0,ec=n-1;


        while(sr<er && sc<ec){
            updateGrid(sr,er,sc,ec,grid,k);
            sr++;
            er--;
            sc++;
            ec--;
        }

        return grid;
    }
};
