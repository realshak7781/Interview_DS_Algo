using ll=long long;
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<pair<ll,int>> maxHeap;
        int n=gifts.size();

        for(int i=0;i<n;i++){
            maxHeap.push({gifts[i],i});
        }


        for(int i=1;i<=k;i++){
            ll pileSize=maxHeap.top().first;
            int idx=maxHeap.top().second;
            maxHeap.pop();

            ll changedPile=(ll)sqrt(pileSize);
            gifts[idx]=changedPile;

            maxHeap.push({gifts[idx],idx});
        }

        ll totalGifts=0;
        for(int g:gifts)totalGifts+=g;

        return totalGifts;
    }
};
