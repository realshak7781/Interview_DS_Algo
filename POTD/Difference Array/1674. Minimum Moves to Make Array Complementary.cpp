class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> diff(2*limit+2,0);

        for(int i=0;i<n/2;i++){
            int minTargetVal=min(nums[i],nums[n-i-1])+1;
            int maxTargetVal=max(nums[i],nums[n-i-1])+limit;

            int sum=nums[i]+nums[n-i-1];
            diff[2]+=2;
            diff[minTargetVal]-=1;
            diff[maxTargetVal+1]+=1;
            diff[2*limit+1]-=2;
            diff[sum]-=1;
            diff[sum+1]+=1;
        }

        for(int i=3;i<=(2*limit+1);i++){
            diff[i]=diff[i-1]+diff[i];
        }
        int minMoves=INT_MAX;
        for(int i=2;i<=2*limit;i++){
            minMoves=min(minMoves,diff[i]);
        }

        return minMoves;
    }

};
