const int mod=1e9+7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        vector<int> powers(n+1);
        powers[0]=1;

        for(int i=1;i<=n;i++){
            powers[i]=(2*powers[i-1]%mod);
        }

        int left=0,right=n-1;
        int result=0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                result=(result+powers[right-left])%mod;
                left++;
            }
            else{
                right--;
            }
        }

        return result;
    }
};
