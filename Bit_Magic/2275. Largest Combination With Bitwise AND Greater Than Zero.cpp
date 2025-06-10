class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();

        int maxSize=0;

        for(int i=0;i<32;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(candidates[j] & (1<<i))count++;
            }
            maxSize=max(count,maxSize);
        }

        return maxSize;
    }
};
