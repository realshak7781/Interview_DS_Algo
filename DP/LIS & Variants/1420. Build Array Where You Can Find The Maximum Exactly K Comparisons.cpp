class Solution {
private:
int n,m,k;
const int mod = 1e9 + 7;
int dp[51][51][102];
int findWays(int idx,int searchCost,int maxSoFar){
    if(idx>=n){
        if(searchCost==k){
            return 1;
        }

        return 0;
    }

    if(dp[idx][searchCost][maxSoFar+1]!=-1) return dp[idx][searchCost][maxSoFar+1];
    int ways=0;
    for(int idxVal=1;idxVal<=m;idxVal++){
        if(idxVal>maxSoFar){
            // searchCost will increase and you can add pruning here 
            ways= (ways+findWays(idx+1,searchCost+1,idxVal))%mod;
        }
        else{
            ways=(ways+findWays(idx+1,searchCost,maxSoFar))%mod;
        }
    }

    return dp[idx][searchCost][maxSoFar+1]=ways%mod;
}
public:
    int numOfArrays(int n, int m, int k) {
        this->n=n;
        this->m=m;
        this->k=k;
        memset(dp, -1, sizeof(dp));
        return findWays(0,0,-1);
    }
};
