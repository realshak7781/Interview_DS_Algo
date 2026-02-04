// Using Sliding window and Two setss
// TIME :O(N*LOG(DIST))
// SPACE : O(DIST)
using ll=long long;
class Solution {
private:
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll totalMinCost=LLONG_MAX;
        int n=nums.size();

        multiset<ll> L; /*stores k-1 elements */
        multiset<ll> R; /*stores rem elements */

        for(int i=1;i<=(dist+1);i++){
            if(L.size()<(k-1)){
                L.insert(1LL*nums[i]);
            }
            else{
                ll maxElem=*L.rbegin();
                if(nums[i]<maxElem){
                    R.insert(maxElem);
                    L.erase(L.find(maxElem));
                    L.insert(nums[i]);
                }
                else{
                    R.insert(nums[i]);
                }
            }
        }

        ll curCost=nums[0];
        for(ll val:L){
            curCost+=val;
        }

        totalMinCost=curCost;

        // sliding window logic here
        for(int i=dist+2;i<n;i++){
            // using sliding window + efficient k-2 minimum cost retrieva
            ll prevElem=nums[i-dist-1];
            ll curElem=nums[i];

            // remove the outgoing element
            if(L.find(prevElem)!=L.end()){
                auto it=L.find(prevElem);
                L.erase(it);
                curCost-=prevElem;
            }
            else if(R.find(prevElem)!=R.end()){
                R.erase(R.find(prevElem));
            }
            // add the incomimg element
            ll maxElem=*L.rbegin();

            if(curElem<maxElem){
                L.insert(curElem);
                curCost+=curElem;
            }
            else{
                R.insert(curElem);
            }


            // try to rebalance
            if(L.size()<(k-1)){
                ll minCost=*R.begin();
                L.insert(minCost);
                curCost+=minCost;
                R.erase(R.find(minCost));
            }
            else if(L.size()>(k-1)){
                ll maxCost=*L.rbegin();
                curCost-=maxCost;
                R.insert(maxCost);
                L.erase(L.find(maxCost));
            }
            // update global min cost;

            totalMinCost=min(totalMinCost,curCost);
        }

        return totalMinCost;
    }
};



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
