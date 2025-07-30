// optimal : O(n)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();

        vector<int> sliceCount(n,0);

        for(int start=2;start<n;start++){
            if((nums[start]-nums[start-1])==(nums[start-1]-nums[start-2])){
                sliceCount[start]=1+sliceCount[start-1];
            }
            else{
                sliceCount[start]=0;
            }
        }
        
        int count=0;

        for(int cnt:sliceCount) count+=cnt;

        return count;
    }
};


//Brute Force Approach O(n^2)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();

        int count=0;

        for(int i=0;i<=(n-3);i++){
            int diff=nums[i+1]-nums[i];

            for(int j=i+2;j<n;j++){
                int cur=nums[j];

                if((nums[j]-nums[j-1])!=diff){
                    break;
                }

                count++;
            }
        }

        return count;
    }
};
