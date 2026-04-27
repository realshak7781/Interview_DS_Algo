class Solution {
private:
int getGoodDistance(vector<int>&nums,int windowSize){
    int n=nums.size();

    int start=0;
    int minDist=INT_MAX;
    int lastIdx=n-windowSize-1;
    while(start<=lastIdx){
        int middle=start+1;
        int end=start+2;

        int curDist=abs(nums[start]-nums[middle])+abs(nums[middle]-nums[end])+abs(nums[start]-nums[end]);
        minDist=min(minDist,curDist);
        start++;
    }
    return minDist;
}
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }


        int minDist=INT_MAX;

        for(auto &it:mp){
            auto &vec=it.second;

            if(vec.size()<3) continue;

            minDist=min(minDist,getGoodDistance(vec,2));
        }

        return minDist==INT_MAX ? -1 : minDist;
    }
};
