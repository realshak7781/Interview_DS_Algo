class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        unordered_map<int,vector<int>> diags;
            
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                  diags[i-j].push_back(mat[i][j]);
            }
        }
        
        for(auto &[key,diag]:diags){
                sort(begin(diag),end(diag));
        }
            
        
         for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                  mat[i][j]=diags[i-j].back();
                  diags[i-j].pop_back();
            }
        }
            
            
            return mat;
            
    }
};
