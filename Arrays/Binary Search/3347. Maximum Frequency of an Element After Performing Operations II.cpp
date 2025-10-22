


// Avoiding the Memory Limit Exceeded
// using Binary Search
class Solution {
private:
    int bs(vector<int>& nums, int l) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= l) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());

        int maxFreq = 0;
        for (int target = 0; target <= maxi; target++) {

            int l = max(0, target - k);
            int r = min(maxi, target + k);

            int upperCnt = upper_bound(begin(nums), end(nums), r) - begin(nums);
            int lowerCnt = bs(nums, l);

            int count = upperCnt - lowerCnt;

            int upperCntTarget =upper_bound(begin(nums), end(nums), target) - begin(nums);
            int lowerCntTarget = bs(nums, target);
            int targetFreq = upperCntTarget - lowerCntTarget;

            int needToConvert = min(count - targetFreq, numOperations);
            int freqInc = targetFreq + needToConvert;

            maxFreq = max(maxFreq, freqInc);
        }

        return maxFreq;
    }
};
