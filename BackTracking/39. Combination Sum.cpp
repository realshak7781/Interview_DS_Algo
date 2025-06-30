class Solution {
private:
    vector<vector<int>> res;

    void createSum(int sum, int idx, vector<int>& candidates, int target, vector<int> temp) {
        if (sum > target || idx >= candidates.size()) return;

        if (sum == target) {
            res.push_back(temp);
            return;
        }

        // pick the current idx (reuse allowed)
        temp.push_back(candidates[idx]);
        createSum(sum + candidates[idx], idx, candidates, target, temp);
        temp.pop_back();

        // don't pick the current
        createSum(sum, idx + 1, candidates, target, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        createSum(0, 0, candidates, target, temp);
        return res;
    }
};
