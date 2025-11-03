


// Brute force : O(k^n)
class Solution {
private:
vector<int> bins;
int tgtSum;
bool solve(int idx,int k,vector<int> &nums){
    if(idx>=nums.size()){
        return true;
    }

    int curSum=nums[idx];

    for(int i=0;i<k;i++){

        if((curSum+bins[i])<=tgtSum){
            bins[i]+=curSum;

            if(solve(idx+1,k,nums)) return true;
            bins[i]-=curSum;
        }
    }

    return false;
}
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum=0;
        for(int val:nums)totalSum+=val;

        if(totalSum%k!=0) return false;
        tgtSum=totalSum/k;

        // check
        for(int val:nums){
            if(val>tgtSum) return false;
        }


        // for fast pruning
        sort(begin(nums),end(nums),greater<int>());
        bins.resize(k,0);
        return solve(0,k,nums);
    }
};
