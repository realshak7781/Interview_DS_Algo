class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        // sort to get the idea of the difference between elems and which can be included in the subsequence
        sort(nums.begin(),nums.end());
        int subCount=0;
        int i=0;
        int start=0;

        while(i<n){
            if((nums[i]-nums[start])>k){
                subCount++;
                start=i;
            }

            i++;
        }

        if(i!=start)subCount++;

        return subCount;
    }
};
