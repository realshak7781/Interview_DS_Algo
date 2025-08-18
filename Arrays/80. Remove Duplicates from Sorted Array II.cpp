class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int pos=2;
        if(nums.size()<=2) return nums.size();


        for(int i=2;i<n;i++){
            if(nums[i]!=nums[pos-2]){
                nums[pos]=nums[i];
                pos++;
            }
        }

        return pos;
    }
};
