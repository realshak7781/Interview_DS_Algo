class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n=original.size();
        int low=bounds[0][0];
        int high=bounds[0][1];

        for(int i=1;i<n;i++){
            if(low>high) return 0;
            int diff=original[i]-original[i-1];
            low=max(low+diff,bounds[i][0]);
            high=min(high+diff,bounds[i][1]);
        }

        if(low>high) return 0;
        
        return (high-low+1);
    }
};
