// Aproach 1 : Time : O(nlogn + maxi*nlogn)
class Solution {
private:
bool binarySearch(vector<int>&nums,int org){
    int low=0;
    int high=nums.size()-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==org) return true;
        else if(nums[mid]>org){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
}
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(begin(nums),end(nums));

        while(true){
            if(binarySearch(nums,original)){
                original*=2;
            }
            else{
                return original;
            }
        }
        return original;
    }
};
