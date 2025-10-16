class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();

        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            nums[i]=(nums[i]%value + value)%value;
            freq[nums[i]]++;
        }

        int mex=0;

        while(true){
            // mex=value+x
            // x=mex-value
            if(freq.count(mex)){
                mex++;
                continue;
            }

            int x=mex-value;
            if(!freq[x] || freq[x]==1) return mex;

            int oldFreq=freq[x];
            freq[x]=1;
            freq[mex]=oldFreq-1;
        }

        return mex;

       
    }
};
