class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);

        for(int i=0;i<n;i++){

            int prevBit=-1;
            bool found=false;
            for(int j=0;j<32;j++){
                if((nums[i] & (1<<j))==0){
                    found = true;
                    prevBit=j-1;
                    break;
                }
            }

            if(found && prevBit>=0){
               int resVal = nums[i]^(1<<prevBit);
               res[i]=resVal;
            }
        }

        return res;
    }
};
