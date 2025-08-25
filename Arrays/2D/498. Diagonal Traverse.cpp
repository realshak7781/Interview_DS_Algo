class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        // if you write down the elements , that belong the same diagonal line,you will observe that: their (i,j) sum to same no;
        // for example : (0,1),(1,0): belong to same line and both add to 1
        // so we will use map to map each element to their sum
        // and then we can observe that we need to reverse the order of the elements only on those idices sum which are even

        unordered_map<int,vector<int>> diagMap;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int diagIdx=i+j;
                diagMap[diagIdx].push_back(mat[i][j]);
            }
        }

        // reverse the even diagIdxs
        for(auto &it:diagMap){
            int diagIdx=it.first;

            if(diagIdx%2==0){
                reverse(it.second.begin(),it.second.end());
            }
        }

        vector<int> res;
        int startDiagIdx=0;
        int endDiagIdx=(n-1)+(m-1);

        for(int i=startDiagIdx;i<=endDiagIdx;i++){
            auto vec=diagMap[i];

            for(auto it:vec){
                res.push_back(it);
            }
        }

        return res;
    }
};
