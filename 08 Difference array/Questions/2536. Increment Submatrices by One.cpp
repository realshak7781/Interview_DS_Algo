class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n,vector<int>(n,0));

        int val=1;
        for(auto q:queries){
            int x1=q[0];
            int y1=q[1];
            int x2=q[2];
            int y2=q[3];

            diff[x1][y1]+=val;
            if(y2+1<n) diff[x1][y2+1]-=val;
            if (x2 + 1 < n) diff[x2 + 1][y1] -= val;
            if (x2 + 1 < n && y2 + 1 < n) diff[x2 + 1][y2 + 1] += val;
        }


        // take row wise and column wise prefix sum
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                diff[i][j]+=diff[i][j-1];
            }
        }

        for(int j=0;j<n;j++){
            for(int i=1;i<n;i++){
                diff[i][j]+=diff[i-1][j];
            }
        }

        return diff;
    }
};
