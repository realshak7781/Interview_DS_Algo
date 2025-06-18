// T.C: O(NLOGN)+O(KLOGN)
// S.C: O(N)

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > minHeap;

        for(int i=0;i<n;i++){
          minHeap.push({nums[i],i});
        }

        for(int i=0;i<k;i++){
            int indx=minHeap.top().second;
            int val=minHeap.top().first;
            minHeap.pop();
            nums[indx]=multiplier*val;

            minHeap.push({nums[indx],indx});
        }
        return nums;
    }
};
