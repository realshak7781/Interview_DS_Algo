class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        // its just a prefix suffix problem :
        vector<int> pref(n,0);
        pref[0]=nums[0];

        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],nums[i]);
        }

        vector<int> suff(n,0);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=min(suff[i+1],nums[i]);
        }
        

        vector<int> res(n,0);
        res[n-1]=pref[n-1];

        for(int i=n-2;i>=0;i--){
            res[i]=pref[i];

            if(pref[i]>suff[i+1]){
                res[i]=res[i+1];
            }
        }

        return res;
    }
};
