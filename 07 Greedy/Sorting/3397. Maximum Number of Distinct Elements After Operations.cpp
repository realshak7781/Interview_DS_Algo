class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        int prev=nums[0]-k;
        int count=1;

        for(int i=1;i<n;i++){
            // take the replacement for each eleemen
            int rangeMin=nums[i]-k;
            int rangeMax=nums[i]+k;

            if(prev<rangeMin){
                prev=rangeMin;
                count++;
            }
            else if(prev<rangeMax){
                prev++;
                count++;
            }
        }

        return count;
    }
};
