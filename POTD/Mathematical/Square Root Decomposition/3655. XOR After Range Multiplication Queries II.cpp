



// Brute force Approach
// TIME : O(Q*N)

const int mod=1e9+7;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
         for(auto &q:queries){
            int l=q[0];
            int r=q[1];
            int k=q[2];
            int v=q[3];

            int idx=l;
            while(idx<=r){
                nums[idx]=(1LL*nums[idx]*v)%mod;
                idx+=k;
            }
        }

        int xorVal=0;
        for(int n:nums){
            xorVal^=n;
        }
        return xorVal;
    }
};
