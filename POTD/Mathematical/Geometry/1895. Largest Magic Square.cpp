// Using Prefix sum to Optimise
// time : O(len*m*n*max(m,n,len))
// space : O(m+1 * n+1)
class Solution {
private:
vector<vector<int>> pref;

int getSum(int r1,int c1,int r2,int c2){

    return pref[r2+1][c2+1] - pref[r2+1][c1] - pref[r1][c2+1] + pref[r1][c1];
}

bool check(int rS,int rE,int cS,int cE,vector<vector<int>>& grid){

    // check all rows 
    int reqSum=getSum(rS,cS,rS,cE);

    for(int i=rS+1;i<=rE;i++){
        // time O(row)
        int rowSum=getSum(i,cS,i,cE);
        if(rowSum!=reqSum) return false;
    }

    // check all columns
    for(int j=cS;j<=cE;j++){
        int colSum=getSum(rS,j,rE,j);

        if(colSum!=reqSum) return false;
    }
     // check both diagonals sum to be same
    //  time O(len)
    int i=rS,j=cS;
    int diagSum1=0;
    while(i<=rE && j<=cE){
        diagSum1+=grid[i][j];
        i++;
        j++;
    }
    if(diagSum1!=reqSum) return false;

    int diagSum2=0;
    int k=rS,l=cE;

    while(k<=rE && l>=0){
        diagSum2+=grid[k][l];
        k++;
        l--;
    }
    if(diagSum2!=reqSum) return false;


    return true;
}
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxSide=min(m,n);

        pref.resize(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pref[i][j]=pref[i-1][j] + pref[i][j-1] + grid[i-1][j-1] - pref[i-1][j-1];
            }
        }

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
