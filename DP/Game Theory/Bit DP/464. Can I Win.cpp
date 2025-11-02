class Solution {
int maxInt;
unordered_map<int,int> dp;
bool solve(int rem,int mask){
    if(rem<=0){
        return false;
    }

    if(dp.count(mask)) return dp[mask];
    for(int i=1;i<=maxInt;i++){
        if ( !(mask & (1 << (i-1))) ){

            int newMask = mask | (1 << (i - 1));
            bool opps=solve(rem-i,newMask);

            if(!opps){
                return dp[mask]=true;
            }
        }
    }

    return dp[mask]=false;
}
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        vector<bool> taken;
        taken.resize(21,false);

        maxInt=maxChoosableInteger;
        int totalSum=(maxInt*(maxInt+1))/2;

        if(totalSum<desiredTotal) return false;

        if (desiredTotal <= 0) return true;
        int mask=0;
        return solve(desiredTotal,mask);
    }
};
