// No extra space :
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();

        while(nums.size()>1){
            int newSize=nums.size()-1;
            for(int i=0;i<newSize;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            nums.resize(newSize);
        }

        return nums[0];
    }
};


// Brute force approach : O(n-1)*O(n)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();

        while(nums.size()>1){
            int newSize=nums.size()-1;
            vector<int> temp(newSize);

            for(int i=0;i<newSize;i++){
                temp[i]=(nums[i]+nums[i+1])%10;
            }
            nums.resize(newSize);
            nums=temp;
        }

        return nums[0];
    }
};
