class Solution {
private:
bool canFormPairsP(vector<int>&nums,int p,int mid){
    int i=0;
    int pairs=0;
    int n=nums.size();
    while(i<n-1){
        if((nums[i+1]-nums[i])<=mid){
            pairs++;
            i+=2;
        }
        else{
            i++;
        }
    }

    return pairs>=p;
}    
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums.back()-nums.front();

        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(canFormPairsP(nums,p,mid)){
                res=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return res;
    }
};
