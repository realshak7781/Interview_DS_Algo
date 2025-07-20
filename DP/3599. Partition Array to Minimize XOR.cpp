const int inf=INT_MAX;
class Solution {
private:
vector<vector<int>> dp;
int recur(int start,vector<int>&nums,int k){
    if(start>=nums.size()){
        if(k==0){
            return 0;
        }
        return inf;
    }

    if(k<=0) return inf;
    if(dp[start][k]!=-1) return dp[start][k];
    int res=inf;
    int curXor=0;
    for(int i=start;i<nums.size();i++){
        curXor^=nums[i];
        int nextXor=recur(i+1,nums,k-1);

        res=min(res,max(curXor,nextXor));
    }

    return dp[start][k]=res;
}
public:
    int minXor(vector<int>& nums, int k) {
        // classic binary search problem:
        int n=nums.size();
        dp=vector<vector<int>>(n+1,vector<int>(k+1,-1));
        return recur(0,nums,k);
    }
};
