class Solution {
int maxKadane(vector<int>&nums){
    int n=nums.size();
    int curMax=0;
    int maxi=INT_MIN;

    for(int i=0;i<n;i++){
        curMax+=nums[i];
        maxi=max(maxi,curMax);

        if(curMax<0)curMax=0;
    }

    return maxi;
}
int minKadane(vector<int>&nums){
    int n=nums.size();
    int curMin=0;
    int mini=INT_MAX;

    for(int i=0;i<n;i++){
        curMin+=nums[i];
        mini=min(mini,curMin);

        if(curMin>0)curMin=0;
    }

    return mini;
}
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxi=maxKadane(nums);
        // this is normal kadane case 1;

        // case 2: circular nature of array : suppose the max subarray sum is s1 then 
        // s1=totalSum-s2;
        // for s1to be max :::  max(s1)=totalSum-min(s2);
        // so the real goal is finding min Sub array sum using Kadane;

        int totalSum=0;
        for(int val:nums)totalSum+=val;
        int s2=minKadane(nums);

        if(totalSum==s2) return maxi;
        int s1=totalSum-s2;

        return max(s1,maxi);
    }
};
