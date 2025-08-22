const int inf=1e4;
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int totalArea=0;
        int rowMin=inf;
        int rowMax=-inf;
        int colMin=inf;
        int colMax=-inf;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;

                rowMin=min(rowMin,i);
                rowMax=max(rowMax,i);
                colMin=min(colMin,j);
                colMax=max(colMax,j);
            }
        }

        totalArea=(rowMax-rowMin+1)*(colMax-colMin+1);
        return totalArea;
    }
};
