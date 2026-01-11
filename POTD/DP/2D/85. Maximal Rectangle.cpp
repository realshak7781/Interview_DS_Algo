
// time : O(m*m*n)
// space : O(m*n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> heights(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') continue;

                if(i>0){
                    heights[i][j]=1+heights[i-1][j];
                }
                else{
                    // only runs for the first row
                    heights[i][j]=1;
                }
            }
        }


        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(heights[i][j]==0) continue;

                int curMinHeight=heights[i][j];
                int k=j;

                while(k>=0 && heights[i][k]>0){
                    int curWidth=j-k+1;
                    curMinHeight=min(curMinHeight,heights[i][k]);
                    int curArea=curMinHeight*curWidth;
                    
                    maxArea=max(maxArea,curArea);
                    k--;
                }
            }
        }

        return maxArea;
    }
};
