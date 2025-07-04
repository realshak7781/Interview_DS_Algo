// APPROACH1:
class Solution {
private:
vector<vector<int>> memo;
int solve(int r,int c,vector<vector<int>>& matrix){
    if(r<0 || c<0) return 0;

    if(matrix[r][c]==0) return 0;

    if(memo[r][c]!=-1) return memo[r][c];

    int top=solve(r-1,c,matrix);
    int left=solve(r,c-1,matrix);
    int diag=solve(r-1,c-1,matrix);

    return memo[r][c]=1+min({top,left,diag});
}    
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        memo.assign(rows+1,vector<int>(cols+1,-1));
        int totalSqCount=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                totalSqCount+=solve(i,j,matrix);
            }
        }

        return totalSqCount;
    }
};

// APPROACH 2:
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> vec=matrix;

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){
                    vec[i][j]=min({vec[i-1][j-1],vec[i-1][j],vec[i][j-1]})+1;
                }
            }
        }

        int totalSq=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                totalSq+=vec[i][j];
            }
        }

        return totalSq;
    }
};
