class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n=cost.size();
        vector<int> res(n,0);

        res[0]=cost[0];
        int mini=cost[0];


        for(int i=1;i<n;i++){
            mini=min(mini,cost[i]);
            res[i]=mini;
        }

        return res;
    }
};
