class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        int prevXi=0;

        vector<bool> res(n,false);
        for(int i=0;i<n;i++){
            int curBit=nums[i];

            int curXi=(2*prevXi+curBit)%5;

            if(curXi==0){
                res[i]=true;
            }

            prevXi=curXi;
        }

        return res;
    }
};
