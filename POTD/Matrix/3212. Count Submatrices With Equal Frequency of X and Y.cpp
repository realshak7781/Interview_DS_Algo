
// Brute force approach 
// TIME : O(R^2 * C^2)
// SPACE : O(1)

class Solution {
bool check(vector<vector<char>>& grid,int r1,int c1,int r2,int c2){

    int countX=0,countY=0;
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            if(grid[i][j]=='X'){
                countX++;
            }
            else if(grid[i][j]=='Y'){
                countY++;
            }
        }
    }

    return countX>0 && countX==countY;
}
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int resCnt=0;

        for(int len=0;len<cols;len++){
            int r1=0,c1=0;
            for(int r=0;r<rows;r++){
                int r2=r,c2=len;

                if(check(grid,r1,c1,r2,c2)){
                    resCnt++;
                }
            }
        }

        return resCnt;
    }
};
