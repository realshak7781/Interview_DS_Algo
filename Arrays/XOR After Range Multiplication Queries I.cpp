const int mod=1e9+7;
using ll=long long;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        
        for(auto&it:queries){
            int li=it[0];
            int ri=it[1];
            int ki=it[2];
            int vi=it[3];

            int idx=li;

            while(idx<n && idx<=ri){
                nums[idx] = (1LL*nums[idx] * vi) % mod;
                idx+=ki;
            }
        }

        int xorVal=0;
        for(int i=0;i<n;i++){
            xorVal=xorVal^nums[i];
        }

        return xorVal;
    }
};
