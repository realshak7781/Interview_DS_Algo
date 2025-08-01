class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> prev={1};

        vector<vector<int>> res;
        res.push_back(prev);
        
        for(int i=2;i<=numRows;i++){
            vector<int> cur;
            cur.push_back(1);

            for(int j=0;j<=i-3;j++){
                int s=prev[j]+prev[j+1];
                cur.push_back(s);
            }
            cur.push_back(1);

            prev=cur;
            res.push_back(prev);
        }

        return res;
    }
};
