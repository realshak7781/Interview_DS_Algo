class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int rowMinMax=INT_MIN;

        for(int i=0;i<m;i++){
            int rowMin=INT_MAX;

            for(int j=0;j<n;j++){
                rowMin=min(rowMin,matrix[i][j]);
            }

            rowMinMax=max(rowMin,rowMinMax);
        }

        int colMaxMin=INT_MAX;
          for(int j=0;j<n;j++){
            int colMax=INT_MIN;

            for(int i=0;i<m;i++){
                colMax=max(colMax,matrix[i][j]);
            }

            colMaxMin=min(colMaxMin,colMax);
        }

        if(rowMinMax==colMaxMin){
            return {rowMinMax};
        }

        return {};

    }
};
