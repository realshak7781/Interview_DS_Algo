// Monotonic Stack
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        int res=0;
        for(int i=0;i<n;i++){
            int cur=nums[i];

            while(!st.empty() && cur<st.top()) st.pop();

            if(st.empty() || cur>st.top()){
                 if(cur>0)res++;
                st.push(cur);
            }
        }

        return res;
    }
};



// Brute Force :TIME : O(UNIQUE*N)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> unique(nums.begin(),nums.end());

        int res=0;
        for(int num:unique){
            if(num==0) continue;

            int i=0;
            while(i<n){
                if(nums[i]==num){
                    res++;
                    while(i<n && nums[i]>=num) i++;
                }
                i++;
            }
        }

        return res;
    }
};
