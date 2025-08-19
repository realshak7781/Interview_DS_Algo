class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int steps=0;

        while(r<(n-1)){
            if(l==r && nums[l]==0) return 0;
            int farthest=0;
            for(int j=l;j<=r;j++){
                farthest=max(farthest,j+nums[j]);
            }
            l=r+1;
            r=farthest;
            steps++;
        }

        return steps;
    }
};
