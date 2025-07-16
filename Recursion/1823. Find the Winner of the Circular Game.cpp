

// brute force approach :
// time: O(nk + nlogn)
// space : O(N)
class Solution {
public:
    int findTheWinner(int n, int k) {
        multiset<int> ms;

        for(int i=1;i<=n;i++){
            ms.insert(i);
        }
        // ms keeps the element in sorted order;
        auto it=ms.begin();
        while(ms.size()>1){

            for(int i=1;i<k;i++){
                ++it;
                if(it==ms.end()){
                    it=ms.begin();
                }
            }
            auto nxt=next(it);
            if(nxt==ms.end()){
                nxt=ms.begin();
            }
            ms.erase(it);
            it=nxt;
        }

        return *it;
    }
};
