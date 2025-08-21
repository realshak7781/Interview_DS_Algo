const int inf=INT_MAX;
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> heights=mat;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(heights[i][j]==0) continue;

                heights[i][j]+=heights[i-1][j];
            }
        }


        int totalCount=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int k=j;
                int minHeight=inf;
                while(k>=0 && heights[i][k]!=0){
                    minHeight=min(minHeight,heights[i][k]);
                    totalCount+=minHeight;
                    k--;
                }
            }
        }

        return totalCount;
    }
};
