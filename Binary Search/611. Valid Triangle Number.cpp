class Solution {
private:
    bool isValid(int a,int b,int c){
        if(a+b>c && a+c>b && b+c>a) return true;
        return false;
    }
    int bruteForce(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int curSum=nums[i]+nums[j];
            }
        }
        return count;
    }

int binarySearch(int imSum,int start,int end,vector<int>&nums){
    int n=nums.size();
    int low=start,high=end;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]<imSum){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

    return low-start;
}
int optimised1(vector<int> nums){
    int n=nums.size();

    sort(nums.begin(),nums.end());
    int  count=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int interMedSum=nums[i]+nums[j];
            count+=binarySearch(interMedSum,j+1,n-1,nums);
        }
    }

    return count;
}
public:
    int triangleNumber(vector<int>& nums) { 
        return optimised1(nums);
    }
};
