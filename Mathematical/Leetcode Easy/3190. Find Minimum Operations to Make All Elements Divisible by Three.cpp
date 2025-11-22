class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int res=0;

        for(int i=0;i<n;i++){
            int val=nums[i];

            if(val%3!=0) res++;
        }

        return res;
    }
};
