// Aproach 1 : Time : O(nlogn + log2(naxi)*nlogn)
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


// Approach 2: using unordered set data structure for fast and efficient lookups
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int maxi=*max_element(begin(nums),end(nums));
        // o(n)
        unordered_set<int> st(begin(nums),end(nums));
        // O(n)

        while(original<=maxi){
            // runs for log2(maxi) times
            if(st.count(original)){
                // o(1) check
                original*=2;
            }
            else{
                return original;
            }
        }
        return original;
    }
};
