class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n=arrivals.size();
        int discarded=0;

        unordered_map<int,int> freq;
        vector<int> kept(n,0);

        for(int right=0;right<n;right++){
            int leftMost=right-w;

            if(leftMost>=0){
                if(kept[leftMost]){
                    freq[arrivals[leftMost]]--;
                }
            }

            int cur=arrivals[right];

            if(freq[cur]<m){
                freq[cur]++;
                kept[right]=1;
            }
            else{
                discarded++;
            }
        }

        return discarded;
    }
};
