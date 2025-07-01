// WITHOUT USING NUMBERS ARRAY:




// USING THE NUMBERS ARRAY:
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<int> nums(n + 1, 0);
        for (int i = 1; i <= n; i++) nums[i] = i;

        ncr(1, nums, k, temp);
        return res;
    }

private:
    vector<vector<int>> res;

    void ncr(int idx, vector<int>& nums, int k, vector<int>& temp) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        if (idx >= nums.size()) return;

        // pick
        temp.push_back(nums[idx]);
        ncr(idx + 1, nums, k, temp);
        temp.pop_back();

        // don't pick
        ncr(idx + 1, nums, k, temp);
    }
};
