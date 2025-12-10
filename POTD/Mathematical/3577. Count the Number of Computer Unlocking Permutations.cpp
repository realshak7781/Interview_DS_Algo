class Solution {
private:
const int mod=1e9+7;
public:
    int countPermutations(vector<int>& complexity) {
        // if the count of minElem is more than one in complexity return 0;
        int n=complexity.size();
        int firstDec=complexity[0];
        int mini=INT_MAX;
        int minCount=0;
        for(int c:complexity){
            mini=min(mini,c);
        }
        // find count of mini
        if(firstDec!=mini) return 0;

        for(int c:complexity){
            if(c==mini)minCount++;
        }

        if(minCount>1) return 0;

        long long count=1;
        for(int i=n-1;i>=1;i--){
            count=(1LL*count*i)%mod;
        }
        return count%mod;
    }
};
