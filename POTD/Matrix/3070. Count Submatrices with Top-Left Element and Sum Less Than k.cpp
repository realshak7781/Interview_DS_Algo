
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
