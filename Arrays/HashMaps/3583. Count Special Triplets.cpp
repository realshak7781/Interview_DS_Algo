const int mod=1e9+7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> totalFreq;
        for(int val:nums) totalFreq[val]++;

        unordered_map<int,int> freqLeft;
        long long ways=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                totalFreq[nums[i]]--;
            }

            int leftCnt=freqLeft[2*nums[i]];
            int totalCnt=totalFreq[2*nums[i]];
            int rightCnt=totalCnt-leftCnt;
            ways=(ways+ 1LL*leftCnt*rightCnt)%mod;

             if(nums[i]==0){
                totalFreq[nums[i]]++;
            }
            freqLeft[nums[i]]++;
        }

        return ways%mod;
    }
};
