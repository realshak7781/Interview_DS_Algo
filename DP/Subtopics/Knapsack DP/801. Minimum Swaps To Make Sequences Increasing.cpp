// Memoized
class Solution {
private:

vector<int> nums1,nums2;
const int inf=INT_MAX;

vector<vector<int>> dp;
int solve(int idx,bool swapElem){
    if(idx>=nums1.size()){
        return 0;
    }

    if(dp[idx][swapElem]!=-1) return dp[idx][swapElem];

    int prevIdx=idx-1;
    if(swapElem){
        swap(nums1[prevIdx],nums2[prevIdx]);
    }

    int prev1=nums1[prevIdx];
    int prev2=nums2[prevIdx];

    int minSwaps=inf;
    if(nums1[idx]>prev1 && nums2[idx]>prev2){
        minSwaps=min(minSwaps,0+solve(idx+1,false));
    }

    if(nums1[idx]>prev2 && nums2[idx] > prev1){
        minSwaps=min(minSwaps,1+solve(idx+1,true));
    }

    if(swapElem)swap(nums1[prevIdx],nums2[prevIdx]);
    return dp[idx][swapElem]=minSwaps;
}
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        this->nums1=nums1;
        this->nums2=nums2;

        dp.resize(n+1,vector<int>(2,-1));
       int dontSwap=0+solve(1,false);
       dp.clear();
       dp.resize(n+1,vector<int>(2,-1));
       int swap=1+solve(1,true);

       return min(swap,dontSwap);
    }
};

// Brute force :
class Solution {
private:

vector<int> nums1,nums2;
const int inf=INT_MAX;

int solve(int idx,bool swapElem){
    if(idx>=nums1.size()){
        return 0;
    }

    int prevIdx=idx-1;
   

    if(swapElem){
        swap(nums1[prevIdx],nums2[prevIdx]);
    }

    int prev1=nums1[prevIdx];
    int prev2=nums2[prevIdx];

    int minSwaps=inf;
    if(nums1[idx]>prev1 && nums2[idx]>prev2){
        minSwaps=min(minSwaps,0+solve(idx+1,false));
    }

    if(nums1[idx]>prev2 && nums2[idx] > prev1){
        minSwaps=min(minSwaps,1+solve(idx+1,true));
    }

    if(swapElem)swap(nums1[prevIdx],nums2[prevIdx]);
    return minSwaps;
}
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;

       int dontSwap=0+solve(1,false);
       int swap=1+solve(1,true);

       return min(swap,dontSwap);
    }
};
