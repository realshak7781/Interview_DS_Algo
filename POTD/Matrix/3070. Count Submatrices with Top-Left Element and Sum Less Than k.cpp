// Optimal approach :  Using Prefix Sum
// Time : O(n*m)
// space : O(n*m)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if(grid[0][0]>k) return 0;

        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>> prefSum(rows+1,vector<int>(cols+1,0));
        // creating the prefix array
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                prefSum[i][j]=grid[i-1][j-1]+prefSum[i-1][j]+prefSum[i][j-1]-prefSum[i-1][j-1];
            }
        }


        int resCnt=0;
        for(int len=0;len<cols;len++){
            int r1=0,c1=0;
            for(int r=0;r<rows;r++){
                int r2=r;
                int c2=len;

                int curSubSum=prefSum[r2+1][c2+1]-prefSum[r2+1][c1]-prefSum[r1][c2+1]+prefSum[r1][c1];

                if(curSubSum<=k){
                    resCnt++;
                }
                else{
                    break;
                }
            }
        }

        return resCnt;
    }
};


// BRUTE FORCE APPROACH
// TIME : O(N^3)
// SPACE : O(1)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if(grid[0][0]>k) return 0;

        int rows=grid.size();
        int cols=grid[0].size();

        int resCnt=0;
        for(int len=0;len<cols;len++){

            int subSum=0;
            for(int r=0;r<rows;r++){
                for(int c=0;c<=len;c++){
                    subSum+=grid[r][c];
                }

                if(subSum<=k){
                    resCnt++;
                }
                else{
                    break;
                }
            }


        }

        return resCnt;
    }
};
