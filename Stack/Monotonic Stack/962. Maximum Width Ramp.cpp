// optimal:

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxRight(n);
        maxRight[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            maxRight[i]=max(maxRight[i+1],nums[i]);
        }

        int ramp=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n && maxRight[j]>=nums[i]){
                ramp=max(ramp,j-i);
                j++;
            }

            if(j==n) return ramp;
        }

        return ramp;
    }
};

// Better : O(n^2)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int ramp=-1;
        for(int j=n-1;j>=0;j--){
            for(int i=0;i<j;i++){
                if(nums[i]<=nums[j]){
                    ramp=max(j-i,ramp);
                    break;
                }
            }
        }


        return ramp==-1 ?0:ramp;
    }
};

//brute force : O(N^2)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]<=nums[j]){
                    maxi=max(maxi,j-i);
                }
            }
        }

        return maxi==-1?0:maxi;
    }
};
