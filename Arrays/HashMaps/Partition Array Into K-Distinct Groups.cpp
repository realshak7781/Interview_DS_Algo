class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()<k) return false;

        // minimum element in each group is k
        // suppose there are x groups
        // x<=(n/k)
        // number of groups lie in the range from x>=1 and x<=(n/k)

        // no of  elements % k ==0 else false

        int n=nums.size();
        if(n%k!=0) return false;

        if(k==1) return true;

        int groupCount=n/k;
        // max groups count needed

        unordered_map<int,int> freq;
        for(int v:nums){
            freq[v]++;
        }


        for(auto &it:freq){
            if(it.second>groupCount) return false;
        }


        return true;

    }
};
