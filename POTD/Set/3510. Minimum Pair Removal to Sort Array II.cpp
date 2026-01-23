
// USING SET DATA STRUCTURE AND THE CONCEPT OF PREViDX AND NEXTIDX TRACKING AND USING THE CONCEPT OF BADPAIRS
// TIME : O(NLOGN)
// SPACE : O(N)
using ll=long long;
class Solution {
private:
int getBadPairsCount(vector<ll>&arr){
    int count=0;

    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]) count++;
    }
    return count;
}

public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        vector<ll> arr(begin(nums),end(nums));

        int badPairs=getBadPairsCount(arr);
        int ops=0;
        set<pair<ll,int>> minSumSet;
        vector<int> nextIdx(n);
        vector<int> prevIdx(n);

        for(int i=0;i<n;i++){
            if(i!=n-1){
                minSumSet.insert({arr[i]+arr[i+1],i});
            }
            nextIdx[i]=i+1;
            prevIdx[i]=i-1;
        }

        while(badPairs>0){
            ops++;

            // get minSum from Set
            auto [minSum,first]=*minSumSet.begin();
            minSumSet.erase(minSumSet.begin());
            // find first,second,firstLeft,secondRight
            int second=nextIdx[first];
            int firstLeft=prevIdx[first];
            int secondRight=nextIdx[second];
            // remove adjacent pairs and insert into set
            if(firstLeft>=0){
                auto it=minSumSet.find({arr[first]+arr[firstLeft],firstLeft});
                if(it!=minSumSet.end())minSumSet.erase(it);
                // also push new pair
                minSumSet.insert({arr[firstLeft]+minSum,firstLeft});
            }
            if(secondRight<n){
                auto it=minSumSet.find({arr[second]+arr[secondRight],second});
                if(it!=minSumSet.end())minSumSet.erase(it);
                minSumSet.insert({arr[secondRight]+minSum,first});
            }
            
            
            // if conditions for badPairs update
            // for the leftSide new pair
            // these are badPairs introduced or reduced from left and rightSide
            if(firstLeft>=0 && arr[firstLeft]>arr[first] && arr[firstLeft]<=(arr[first]+arr[second])){
                badPairs--;
            }
            else if(firstLeft>=0 && arr[firstLeft]<=arr[first] && arr[firstLeft] > (arr[first]+arr[second])){
                badPairs++;
            }

            // for the rightSide new pair
            if(secondRight<n && arr[second]<=arr[secondRight] && (arr[first]+arr[second])>arr[secondRight]){
                badPairs++;
            }
            else if(secondRight<n && arr[second]>arr[secondRight] && (arr[first]+arr[second])<=arr[secondRight]){
                badPairs--;
            }

            // checking the current bad pair
            if(arr[first]>arr[second]) badPairs--;

             // update nextIdx,prevIdx,arr
            if(secondRight<n)prevIdx[secondRight]=first;
            nextIdx[first]=secondRight;
            arr[first]+=arr[second];
        }

        return ops;
    }
};
