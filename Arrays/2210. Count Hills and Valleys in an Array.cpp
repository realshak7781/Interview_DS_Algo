// optimal soluton :
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int prev=0;

        int count=0;
        for(int i=1;i<=n-2;i++){
            int high=i+1;

            // plateau region
            if(nums[i]==nums[high]) continue;

            if(nums[i]>nums[prev] && nums[i]>nums[high]){
                count++;
            }
            else if(nums[i]<nums[prev] && nums[i]<nums[high]){
                count++;
            }

            prev=i;
        }
        return count;
    }
};

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 1; i <= n - 2; i++) {
            if (nums[i] == nums[i - 1]) continue;

            int high = i + 1;
            while (high < n && nums[high] == nums[i]) high++;

            int prev = i - 1;
            while (prev >= 0 && nums[prev] == nums[i]) prev--;

            if (prev >= 0 && high < n) {
                if (nums[i] > nums[prev] && nums[i] > nums[high]) {
                    count++;
                } else if (nums[i] < nums[prev] && nums[i] < nums[high]) {
                    count++;
                }
            }
        }

        return count;
    }
};
