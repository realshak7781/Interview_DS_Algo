// Leetcode POTD 31 july 2025

// Time : O(32*N)

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> cur;
        unordered_set<int> res;

        for(int i=0;i<arr.size();i++){

            for(int x:prev){
                cur.insert(x|arr[i]);
                res.insert(x|arr[i]);
            }
            cur.insert(arr[i]);
            res.insert(arr[i]);
            prev=cur;

            cur.clear();
        }

        return res.size();
    }
};
