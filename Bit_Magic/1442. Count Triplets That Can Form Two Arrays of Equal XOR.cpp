class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixXor(n);
        prefixXor[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixXor[i]=prefixXor[i-1]^nums[i];
        }

        // traverse the prefixXor array to find subarrays of len>=2 beacause those subarrays will contribute to the count=(len-1);

        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int xorVal;
                int len=j-i+1;
                if(i==0){
                    xorVal=prefixXor[j];
                }
                else{
                    xorVal=prefixXor[j]^prefixXor[i-1];
                }
                if(xorVal==0 && len>=2){
                    count=count+(len-1);
                }
            }
        }

        return count;
    }
};
