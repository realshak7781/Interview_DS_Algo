class Solution {  
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int limit=(1<<maximumBit)-1;
        int n=nums.size();
        vector<int> pfXor(n);
        pfXor[0]=nums[0];

        for(int i=1;i<n;i++){
            pfXor[i]=pfXor[i-1]^nums[i];
        }

        vector<int> res(n);

        for(int i=0;i<n;i++){
            res[i]=pfXor[n-i-1]^limit;
        }

        return res;
    }
};
