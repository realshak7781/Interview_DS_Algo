

//BRUTE FORCE SOLUTION:
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> res;

        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[j]==key && abs(i-j)<=k){
                    res.push_back(i);
                    break;
                }
            }
        }
        sort(res.begin(),res.end());

        return res;
    }
};
