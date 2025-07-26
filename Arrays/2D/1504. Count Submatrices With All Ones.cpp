class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
         int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>>height(m,vector<int>(n,0));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                if(i-1>=0){
                    height[i][j]=height[i-1][j]+1;
                }
                else{
                    height[i][j]=1;
                }
            }
            else{
                height[i][j]=0;
            }
        }
      }
        
        int total=0;
        
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(height[i][j]==0) continue;
            
            int minHeight=height[i][j];
            
            for(int k=j;k>=0 && height[i][k]>0 ; k--){
                minHeight=min(minHeight,height[i][k]);
                total+=minHeight;
            }
        }
      }

      return total;
       
    }
};
