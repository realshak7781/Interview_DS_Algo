using ll = long long;
class Solution {
private:
    int brute(vector<int>& nums, int p) {
        int n = nums.size();

        long long totalSum = accumulate(begin(nums), end(nums), 0LL);

        if (totalSum % p == 0)
            return 0;

        vector<long long> pfSum(n);
        pfSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pfSum[i] = pfSum[i - 1] + nums[i];
        }

        int resLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int curLen = j - i + 1;
                long long curSum = pfSum[j] - (i > 0 ? pfSum[i - 1] : 0);
                long long remSum = totalSum - curSum;

                if (remSum % p == 0 && curLen < resLen) {
                    resLen = curLen;
                    break;
                }
            }
        }

        if (resLen == INT_MAX || resLen == n)
            return -1;

        return resLen;
    }

public:
    int minSubarray(vector<int>& nums, int p) {


        // theory :
        // supppose the array is : a1,a2,a3,a4,a5,a6
        // and the subarray to be removed smallest one is : a3,a4,a5
        // that gives : (totalSum-(a3+a4+a5))%k==0
        // solving te eqn : to get the sum effectively in o(1) time of a3,a4,a5 we use cumulative sum concept or prefx SUm
        // (a3+a4+a5)%k==totalSum%k
        // (p[j]-p[i-1])%k==target(totalSum%k)
        // if i...j reprresent the subarray a3,a4,a5
        // final eqn to implement : (p[j]-target+p)%p==target  here p=k
        int n = nums.size();
        long long totalSum = 0;

        for (int x : nums)
            totalSum += x;

        int target = totalSum % p;
        if (target == 0)
            return 0;

        unordered_map<int, int> mp;

        mp[0] = -1;

        long long curSum = 0;
        int minLen = n;

        for (int j = 0; j < n; ++j) {
            curSum += nums[j];
            int curMod = curSum % p;

            int needed = (curMod - target + p) % p;

            if (mp.count(needed)) {
                minLen = min(minLen, j - mp[needed]);
            }

            mp[curMod] = j;
        }

        return minLen < n ? minLen : -1;
    }
};
