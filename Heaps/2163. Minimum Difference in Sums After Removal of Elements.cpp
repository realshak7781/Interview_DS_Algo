using ll=long long;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/3;

        vector<ll>leftMin(N,-1);
        vector<ll>rightMax(N,-1);
      // space : O(2*N)

        // build the leftMax
        // we want the leftSum to be as min as possible and it should be the sum of exactly n elements  so in the sum whenever we have taken more than n digits , to make the sum min remove the ,max element added so far;
        priority_queue<ll> maxHeap;
        ll curSum=0;
      // time : O(n*logn) = O(NLogN) cause n=N/3;
      // space : o(n)
        for(int i=0;i<=(2*n-1);i++){
            curSum+=nums[i];
            maxHeap.push(nums[i]);
            if(maxHeap.size()>n){
                curSum-=maxHeap.top();
                maxHeap.pop();
            }
            leftMin[i]=curSum;
        }
        // same logic applies for rightSum: make it as large as possible using minHeap;
       // time : O(n*logn) = O(NLogN) cause n=N/3;
      // space : o(n)
        priority_queue<ll,vector<ll>,greater<ll>> minHeap;
        curSum=0;
        for(int i=N-1;i>=n;i--){
            curSum+=nums[i];
            minHeap.push(nums[i]);

            if(minHeap.size()>n){
                curSum-=minHeap.top();
                minHeap.pop();
            }
            rightMax[i]=curSum;
        }


        ll res=LLONG_MAX;

        for(int i=n-1;i<=(2*n-1);i++){
          // O(n)
            res=min(res,leftMin[i]-rightMax[i+1]);
        }

        return res;
    }
};
