
// Time : O(r*col*log(r))
// space : O(r*c)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<vector<int>> height=matrix;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0) continue;

                int prevColVal= (i>0 ? height[i-1][j] : 0);
                height[i][j]+=prevColVal;
            }
        }

        int resArea=0;
        for(int i=0;i<rows;i++){
            auto vec=height[i];
            sort(begin(vec),end(vec),greater<int>());

            int minHeight=1e9;
            int base=0;

            for(int j=0;j<cols;j++){
                int curHeight=vec[j];
                if(curHeight==0){
                    base=0;
                    minHeight=1e9;
                }else{
                    minHeight=min(curHeight,minHeight);
                    base+=1;

                    resArea=max(resArea,base*minHeight);
                }
            }
        }


        return resArea;
    }
};
