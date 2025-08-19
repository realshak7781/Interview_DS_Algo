class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // You can clearly observe in the problem that:
        // for any continous subarray of 0s like : [0,0,0,0,0]
        // if size is 5: 
        // /no of arrays of size1:5
        // /no of arrays of size2:4
        // /no of arrays of size3:3
        // /no of arrays of size4:2
        // /no of arrays of size5:1
        // so for any subarray of continuous subarrays the number of subarrays filled with 0: n*(n+1)/2
        // where n: size of subarray

        // Use a sliding window+ maths formula:

        int n=nums.size();
        int j=0;
        long long totalCount=0;
        while(j<n){
            if(nums[j]!=0){
                j++;
                continue;
            }
            int i=j;
            while(j<n && nums[j]==0) j++;

            long long count=j-i;

            totalCount+= ((count)*(count+1))/2;
        }

        return totalCount;
    }
};
