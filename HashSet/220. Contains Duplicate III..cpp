class Solution {
private:
bool optimised(vector<int>& nums, int indexDiff, int valueDiff){
    int n=nums.size();
    multiset<long long> ms;

    for(int j=0;j<n;j++){
        // try to find a n[i]>=n[j]-valueDiff exists or not in the multiset

        auto it=ms.lower_bound(nums[j]-valueDiff);

        if(it!=ms.end() && *it<=(nums[j]+valueDiff)) return true;

        ms.insert(nums[j]);

        // try maintaining a window of size (indexDiff)

        if(j>=indexDiff){
            auto it=ms.find(nums[j-indexDiff]);
            if(it!=ms.end()){
                ms.erase(it);
            }
        }
    }

    return false;
}    
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        // BRUTE FORCE SOLUTION : O(N^2)
        // int n=nums.size();

        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(abs(i-j)<=indexDiff && abs(nums[i]-nums[j])<=valueDiff){
        //             return true;
        //         }
        //     }
        // }

        // return false;

        return optimised(nums,indexDiff,valueDiff);
    }
};
