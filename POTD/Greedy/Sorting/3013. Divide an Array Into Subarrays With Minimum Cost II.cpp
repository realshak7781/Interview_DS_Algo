
// SOLVING THE PART TWO OF THE PROBLEM
// USING BRUTE FORCE APPROACH : O(N*N*LOGN)
// SPACE : O(N)
using ll=long long;
class Solution {
private:
ll getRemCost(vector<int>& nums,int k,int start,int end){

    priority_queue<ll> maxHeap;
    for(int i=start;i<=end;i++){

        if(maxHeap.size()<k){
            maxHeap.push(1LL*nums[i]);
        }
        else{
            if(maxHeap.top()>nums[i]){
                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
        }
    }

    ll remCost=0;

    while(!maxHeap.empty()){
        remCost+=maxHeap.top();
        maxHeap.pop();
    }

    return remCost;
}
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll totalMinCost=LLONG_MAX;
        int n=nums.size();

        for(int i=1;i<=(n-k+1);i++){
            ll secondCost=nums[i];

            int endIdx=min(n-1,i+dist);
            ll remCost=getRemCost(nums,k-2,i+1,endIdx);

            totalMinCost=min(totalMinCost,nums[0]+secondCost+remCost);
        }

        return totalMinCost;
    }
};
