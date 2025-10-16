using ll=long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<ll> colSum(n,0);
        vector<ll> rowSum(m,0);

        for(int j=0;j<n;j++){
            ll sum=0;
            for(int i=0;i<m;i++){
                sum+=grid[i][j];
            }
            colSum[j]=sum;
        }

        // calculating the row sum
        for(int i=0;i<m;i++){
            ll sum=0;
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
            }
            rowSum[i]=sum;
        }


        // compute prefix Sums of both
        vector<ll> colPref(n,0);
        vector<ll> rowPref(m,0);

        colPref[0]=colSum[0];
        for(int j=1;j<n;j++){
            colPref[j]=colPref[j-1]+colSum[j];
        }

        rowPref[0]=rowSum[0];
        for(int i=1;i<m;i++){
            rowPref[i]=rowPref[i-1]+rowSum[i];
        }

        // now check for partition

        // first check vertical partitions;
        for(int j=0;j<n-1;j++){
            ll leftSum=colPref[j];
            ll rightSum=colPref[n-1]-colPref[j];

            if(leftSum==rightSum) return true;
        }


        // check horizontal partitions
        for(int i=0;i<m-1;i++){
            ll topSum=rowPref[i];
            ll botSum=rowPref[m-1]-rowPref[i];

            if(topSum==botSum) return true;
        }

        return false;
    }
};
