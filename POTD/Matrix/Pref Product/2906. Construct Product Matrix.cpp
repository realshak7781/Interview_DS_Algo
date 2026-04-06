// Using Prefix Prod 

const int mod=12345;
using ll=long long;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>> prefProd(rows,vector<int>(cols,1));
        prefProd[0][0]=1;
        vector<vector<int>> sufProd(rows,vector<int>(cols,1));
        sufProd[rows-1][cols-1]=1;

        ll startProd=grid[0][0];

        // populating prefProd
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 && j==0) continue;
                prefProd[i][j]=startProd%mod;
                startProd=(1LL*startProd*grid[i][j])%mod;
            }
        }

        // populating sufProd
        ll endProd=grid[rows-1][cols-1];
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(i==rows-1 && j==cols-1) continue;
                sufProd[i][j]=endProd%mod;
                endProd=(1LL*endProd*grid[i][j])%mod;
            }
        }


        vector<vector<int>> res(rows,vector<int>(cols,1));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ll prod=(1LL*prefProd[i][j]*sufProd[i][j])%mod;
                res[i][j]=prod;
            }
        }

        return res;
    }
};
