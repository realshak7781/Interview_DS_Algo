using ll=long long;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        ll totalSum=0;
        ll minNegVal=INT_MAX;
        int negValCount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val=matrix[i][j];

                totalSum+=abs(val);
                if(val<0){
                   negValCount++;
                }

                 minNegVal=min(minNegVal,abs(1LL*val));
            }
        }


        if(negValCount%2==1){
            totalSum-=(2LL*minNegVal);
        }

        return totalSum;
    }
};
