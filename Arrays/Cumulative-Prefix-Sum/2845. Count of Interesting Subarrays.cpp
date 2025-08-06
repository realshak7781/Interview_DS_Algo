using ll=long long;
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        int m=modulo;

        for(int i=0;i<n;i++){
            int modVal=nums[i]%m;
            if(modVal==k){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }


        unordered_map<ll,ll> cumSum;
        cumSum[0]=1;

        ll count=0;
        ll runSum=0;
        for(int i=0;i<n;i++){
            runSum+=nums[i];

            ll r1=runSum%m;
            ll r2=(r1-k+m)%m;

            count+=(long long)cumSum[r2];

            cumSum[r1]++;
        }

        return count;
    }
};
