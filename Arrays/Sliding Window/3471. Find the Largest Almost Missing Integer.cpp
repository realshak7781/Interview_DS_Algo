class Solution {
private:
int bruteForce(vector<int>&nums,int k){
    int n=nums.size();
    // brute force approach :  time complxity : O(n*k)
    unordered_map<int,int> mp;

    for(int i=0;i<k;i++){
        if(!(mp.count(nums[i]))){
            mp[nums[i]]++;
        }
    }

    for(int w=k;w<n;w++){
        mp[nums[w]]++;

        int start=w-k+1;
        for(int j=start;j<w;j++){
            mp[nums[j]]++;
        }
    }

    int maxi=-1;
    for(auto it:mp){
        if(it.second==1){
            maxi=max(maxi,it.first);
        }
    }

    return maxi;
}

int optimal(vector<int>&nums,int k){
    int n=nums.size();
    // we need to solve three cases 
    // case 1 : k=1 : return the largest element that occurs just once 
    // case 2 : k=n : return the largest element element in the array
    // case 3 : pick the largest of nums[0] && nums[n-1] : but both should ooccur only once '
    // case 4 : return -1;

    unordered_map<int,int> mp;
    int maxi=-1;
    for(int val:nums){
        mp[val]++;
        maxi=max(maxi,val);
    }

    if(k==n) return maxi;
    if(k==1 && mp[maxi]==1) return maxi;

    int res=-1;
    if(k==1){
        for(auto it:mp){
            if(it.second==1){
                res=max(res,it.first);
            }
        }
        return res;
    }
    else{
        if(mp[nums[0]]==1){
            res=max(nums[0],res);
        }

        if(mp[nums[n-1]]==1){
            res=max(res,nums[n-1]);
        }
    }

    return res;
}
public:
    int largestInteger(vector<int>& nums, int k) {
        return optimal(nums,k);
    }
};
