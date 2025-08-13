class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                count++;
            }
        }
        
        int k=n-count;
        int i=0;
        int j=n-1;
        
        while(i<n && i<j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
            }
            i++;
        }
        
        return k;
    }
};
