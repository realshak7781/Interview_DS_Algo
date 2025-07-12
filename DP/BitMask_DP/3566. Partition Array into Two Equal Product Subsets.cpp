using ll=__int128;
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll prod=1;

        for(auto&it:nums){
            prod*=it;

            if(prod> (ll)((ll)target*(ll)target)) return false;
        }

        if(prod!=(ll)((ll)target*(ll)target)) return false;

        int n=nums.size();
        int maxi=1<<n;
        for(int i=1;i<maxi-1;i++){
            ll subProd=1;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    subProd*=nums[j];
                    if(subProd>target) break;
                }
            }
            if(subProd==target) return true;
        }

        return false;
    }
};
