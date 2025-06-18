class Solution {
int optimised(vector<int>&nums){
    int n=nums.size();
    if(n==0) return 0;
    unordered_set<int> st(nums.begin(),nums.end());

    int maxLen=0;

    for(int num:st){
        if(!st.count(num-1)){
            int curLen=1;
            int cur=num;

            while(st.count(cur+1)){
                curLen++;
                cur++;
            }
            maxLen=max(curLen,maxLen);
        }
    }

    return maxLen;
}    
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // if(n==0) return 0;
        // int maxLen=1;
        // int curLen=1;

        // for(int i=1;i<n;i++){
        //     if(nums[i]==nums[i-1]){
        //         continue;
        //     }
        //     else if((nums[i]-nums[i-1])==1) curLen++;

        //     else{
        //         maxLen=max(maxLen,curLen);
        //         curLen=1;
        //     }
        // }

        // return max(maxLen,curLen);

        return optimised(nums);
    }
};
