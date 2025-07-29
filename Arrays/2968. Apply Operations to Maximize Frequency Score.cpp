using ll=long long;
class Solution {
private:
    bool isPossible(int mid, long long k, vector<int>& nums, int n, vector<ll>& prefSum) {
        int i = 0, j = mid - 1;

        while (j < n) {
            ll targetIdx = (i + j) / 2;
            ll target = nums[targetIdx];

            ll leftOpCount=0;
            ll rightOpCount=0;

            if(targetIdx>0){
                leftOpCount=abs((targetIdx-i)*target -(prefSum[targetIdx-1]-(i>0?prefSum[i-1]:0)));
            }

            rightOpCount=abs((j-targetIdx)*target-(prefSum[j]-prefSum[targetIdx]));

            ll totalOpCount=leftOpCount+rightOpCount;
            if (totalOpCount <= k) {
                return true;
            }
            else {
                i++;  
                j++;  
            }
        }

        return false;
    }

public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<ll> prefSum(n);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        int minScore = 1, maxScore = n;
        int res = 1;

        while (minScore <= maxScore) {
            int mid = minScore + (maxScore - minScore) / 2;

            if (isPossible(mid, k, nums, n, prefSum)) {
                minScore = mid + 1;
                res = mid;
            }
            else {
                maxScore = mid - 1;
            }
        }

        return res;
    }
};
