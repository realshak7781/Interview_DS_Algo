class Solution {
private:
int optimised(vector<int>&nums){
    int n=nums.size();
    vector<int> pre(n);
    vector<int> suff(n);

    int mini=nums[0];
    pre[0]=nums[0];
    for(int i=1;i<n;i++){
        mini=min(nums[i],mini);
        pre[i]=mini;
    }

    int maxi=nums[n-1];
    suff[n-1]=nums[n-1];

    for(int i=n-2;i>=0;i--){
        maxi=max(maxi,nums[i]);
        suff[i]=maxi;
    }


    int maxDiff=-1;

    for(int i=0;i<n;i++){
        maxDiff=max(maxDiff,suff[i]-pre[i]);
    }

    return maxDiff==0 ? -1 : maxDiff;
}    
public:
    int maximumDifference(vector<int>& nums) {
        // int maxi=-1;
        // int n=nums.size();

        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if((nums[i]-nums[j])<0){
        //             maxi=max(abs(nums[i]-nums[j]),maxi);
        //         }
        //     }
        // }

        // return maxi;

        return optimised(nums);
    }
};
