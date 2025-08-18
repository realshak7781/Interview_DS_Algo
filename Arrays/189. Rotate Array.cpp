class Solution {
private:
void reverse(int i,int j,vector<int>&nums){
    
    while(i<=j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;

        if(k==0) return ;

        reverse(0,n-1,nums);

        reverse(0,k-1,nums);

        reverse(k,n-1,nums);
    }
};
