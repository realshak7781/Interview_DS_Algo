class Solution {
// TIME: O(2^N *N)
// SPACE: O(1)
int bruteForce(vector<int>&nums){
    int n=nums.size();

    int xorSum=0;
    for(int i=0;i<(1<<n);i++){
        int xorVal=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                xorVal^=nums[j];
            }
        }
        xorSum+=xorVal;
    }

    return xorSum;
}

// TIME:O(2^N)
// SPACE:O(N)
int xorSum=0;
void backTrack(int idx,int xorVal,vector<int>&nums){
    if(idx>=nums.size()){
        xorSum+=xorVal;
        return;
    }

    // notPick currentElemet
    backTrack(idx+1,xorVal,nums);
    backTrack(idx+1,xorVal^nums[idx],nums);
}

// Observation bases approaches
int optimised(vector<int>&nums){
    int n=nums.size();
    int zeroesToAppend=n-1;

    int orVal=0;
    for(int &v:nums){
        orVal|=v;
    }

    return orVal<<zeroesToAppend;
}
public:
    int subsetXORSum(vector<int>& nums) {
        // return bruteForce(nums);
        // backTrack(0,0,nums); /*xorSum global is for backTracking solution*/
        // return xorSum;

        return optimised(nums);
    }
};
