class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        // property: bitwise and of any two numbers is <=max(both nos)
        // for the equality to hold both nos need to be same or all numbers need to be same

        // now the next thing is finding : max and  value in the array
        // since anding anding elemnts either decreases or stays same : the max and is a single value : max element of the array:

        int maxAnd=*max_element(begin(nums),end(nums));

        int i=0;
        int maxLen=0;
        while(i<n){

            if(nums[i]==maxAnd){
                int j=i;

                while(j<n && nums[j]==maxAnd){
                    j++;
                }
                maxLen=max(maxLen,j-i);
                i=j;
            }
            else{
                i++;
            }
        }

        return maxLen;
    }
};
