// Optimal approach:
// TIME : O(R*C)
// SPACE : O(R*C)

class Solution {
private:
vector<vector<int>> xCnt,yCnt;
bool check(int r1,int c1,int r2,int c2){

    int countX=xCnt[r2+1][c2+1]-xCnt[r1][c2+1]-xCnt[r2+1][c1]+xCnt[r1][c1];
    int countY=yCnt[r2+1][c2+1]-yCnt[r1][c2+1]-yCnt[r2+1][c1]+yCnt[r1][c1];

    return countX>0 && countX==countY;
}
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        xCnt.resize(rows+1,vector<int>(cols+1,0));
        yCnt.resize(rows+1,vector<int>(cols+1,0));

        // create the count arrays
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                int prevX=xCnt[i-1][j]+xCnt[i][j-1]-xCnt[i-1][j-1];
                int prevY=yCnt[i-1][j]+yCnt[i][j-1]-yCnt[i-1][j-1];

                char cur=grid[i-1][j-1];

                if(cur=='X'){
                    xCnt[i][j]=1+prevX;
                    yCnt[i][j]=prevY;
                }
                else if(cur=='Y'){
                    yCnt[i][j]=1+prevY;
                    xCnt[i][j]=prevX;
                }
                else{
                    xCnt[i][j]=prevX;
                    yCnt[i][j]=prevY;
                }
            }
        }


        int resCnt=0;
        for(int len=0;len<cols;len++){
            int r1=0,c1=0;
            for(int r=0;r<rows;r++){
                int r2=r,c2=len;

                if(check(r1,c1,r2,c2)){
                    resCnt++;
                }
            }
        }

        return resCnt;
    }
};


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
