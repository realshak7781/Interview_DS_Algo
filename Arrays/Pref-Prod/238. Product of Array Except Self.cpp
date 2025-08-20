class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefProd(n);
        vector<int> suffProd(n);

        prefProd[0]=nums[0];
        suffProd[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            prefProd[i]=prefProd[i-1]*nums[i];
        }

        for(int i=n-2;i>=0;i--){
            suffProd[i]=suffProd[i+1]*nums[i];
        }


        vector<int> res(n);

        for(int i=0;i<n;i++){

            int prevProd=(i>0?prefProd[i-1]:1);
            int afterProd=(i<n-1?suffProd[i+1]:1);

            res[i]=prevProd*afterProd;
        }

        return res;
    }
};
