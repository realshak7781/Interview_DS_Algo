class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;

        int originalSize=original.size();
        if((m*n)!=originalSize) return res;
        res=vector<vector<int>>(m,vector<int>(n,0));
        for(int i=0;i<originalSize;i++){
            int colIdx=i%n;
            int rowIdx=i/n;

            res[rowIdx][colIdx]=original[i];
        }

        return res;
    }
};
