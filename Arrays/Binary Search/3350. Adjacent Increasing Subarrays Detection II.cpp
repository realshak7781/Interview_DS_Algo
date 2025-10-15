
// Using the Linear Loop O(n*n) approach
class Solution {
private:
bool check(vector<int>&indices,int k){
     unordered_set<int> st;

        // check for the last index
        for(int i=0;i<indices.size();i++){
            int curIdx=indices[i];
            int prevIdx=curIdx-k;

            if(st.count(prevIdx)) return true;

            st.insert(curIdx);
        }

        return false;
}

bool isValid(vector<int>&nums,int k){
     int n=nums.size();
        vector<int> indices;


        // when k=1
        if(k==1){
            for(int i=0;i<n;i++) indices.push_back(i);

            return check(indices,k);
        }

        // when k>1
        int left=0;
        for(int right=1;right<n;right++){
            if(nums[right]>nums[right-1]){
                if((right-left+1)==k){
                    indices.push_back(left);
                    left++;
                }
            }
            else if(nums[right]<=nums[right-1]){
                left=right;
            }
        }

       

       return check(indices,k);
}
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int low=1;
        int high=n/2;

        for(int k=high;k>=low;k--){
            if(isValid(nums,k)) return k;
        }

        return 1;
    }
};
