using ll=long long;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0) return 0;

        int res=0;
        ll prod=1;
        int i=0;

        for(int j=0;j<n;j++){
            prod*=nums[j];

            while(i<=j && prod>=k){
                prod/=nums[i];
                i++;
            }

            if(i<=j){
                res+=(j-i+1);
            }
        }

        return res;
    }
};
