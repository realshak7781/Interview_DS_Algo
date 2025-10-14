// APPROACH 2:
// USING SLIDING WINDOW + HASHSET
// T.C:O(nlogn)
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
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
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
};



// APPROACH 1:
// Brute Force : O(n^2) : ACCEPTED
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        for(int i=0;i<=(n-2*k);i++){
            int j=i+1;

            while((j-i)<k){
                // for first subarray
                if(nums[j]<=nums[j-1]) break;
                j++;
            }

            if((j-i)<k) continue;

            // second subarray
            // j holds the index of the starting of the next subarray
            int m=j+1;
            while((m-j)<k){
                if(nums[m]<=nums[m-1]) break;
                m++;
            }

            if(m-j < k) continue;

            return true;
        }

        return false;
    }
};
