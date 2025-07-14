using ll=long long;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int res=INT_MAX;
        deque<int> dq;
        vector<ll> cumSum(n,0);
        int j=0;

        while(j<n){
            if(j==0){
                cumSum[j]=nums[j];
            }
            else{
                cumSum[j]=nums[j]+cumSum[j-1];
            }

            if(cumSum[j]>=k){
                res=min(res,j+1);
            }

            while(!dq.empty() && cumSum[j]-cumSum[dq.front()]>=k){
                res=min(res,j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && cumSum[j]<=cumSum[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);
            j++;
        }

        return res==INT_MAX?-1:res;
    }
};
