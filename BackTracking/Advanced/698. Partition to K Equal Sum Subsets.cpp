class Solution {
private:
int n;
int tgtSum;
vector<bool> used;

bool solve(int idx,int subsetSum,vector<int>&nums,int k){
    if (k == 0) {
            return true;
    }
    if(subsetSum==tgtSum){
        return solve(0,0,nums,k-1);
    }


    for(int j=idx;j<n;j++){
        if(used[j] || (subsetSum+nums[j])>tgtSum){
            continue;
        }

        used[j]=true;
        if(solve(j+1,subsetSum+nums[j],nums,k)) return true;
        used[j]=false;
    }


    return false;
}
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum=0;
        for(int val:nums) totalSum+=val;

        if(totalSum%k!=0) return false;

        tgtSum=totalSum/k;

        for(int val:nums){
            if(val>tgtSum) return false;
        }

        n = nums.size();
        used.assign(n,false);

        return solve(0,0,nums,k);
    }
};
