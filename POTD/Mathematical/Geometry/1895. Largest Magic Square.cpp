
// Using Brute force approach and sliding window on rows and columns
// Time ~~ o(len*m^2*n^2)
// space : O(1)
class Solution {
private:
bool check(int rS,int rE,int cS,int cE,vector<vector<int>>& grid){
    // check all row sum to be same
    int sum=0;
    for(int j=cS;j<=cE;j++){
        sum+=grid[rS][j];
    }
    for(int i=rS+1;i<=rE;i++){
        int rowSum=0;
        for(int j=cS;j<=cE;j++){
            rowSum+=grid[i][j];
        }
        if(rowSum!=sum) return false;
    }
    // check all column  sum to be same

    for(int j=cS;j<=cE;j++){
        int colSum=0;
        for(int i=rS;i<=rE;i++){
            colSum+=grid[i][j];
        }

        if(colSum!=sum) return false;
    }

    // check both diagonals sum to be same
    int i=rS,j=cS;
    int diagSum1=0;
    while(i<=rE && j<=cE){
        diagSum1+=grid[i][j];
        i++;
        j++;
    }
    if(diagSum1!=sum) return false;

    int diagSum2=0;
    int k=rS,l=cE;

    while(k<=rE && l>=0){
        diagSum2+=grid[k][l];
        k++;
        l--;
    }
    if(diagSum2!=sum) return false;


    return true;
}
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxSide=min(m,n);

        for(int len=maxSide;len>1;len--){
            
            for(int i=0;i<=(m-len);i++){
                // sliding window on rows
                for(int j=0;j<=(n-len);j++){
                    // sliding windows on cols
                    int rS=i;
                    int rE=i+len-1;
                    int cS=j;
                    int cE=j+len-1;

                    if(check(rS,rE,cS,cE,grid)) return len;
                }
            }
        }

        return 1;
    }
};
