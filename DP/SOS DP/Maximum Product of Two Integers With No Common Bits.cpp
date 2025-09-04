using ll=long long;
class Solution {
private:
int countBits(int n){
    int count=0;

    while(n>0){
        count++;
        n/=2;
    }

    return count;
}
public:
    long long maxProduct(vector<int>& nums) {
        int mx=*max_element(begin(nums),end(nums));

        int maxBits=countBits(mx);
        int maxBitNo=(1<<maxBits)-1;

        vector<ll> dp(maxBitNo+1,0);

        for(int num:nums){
            dp[num]=num;
        }

        for(int i=0;i<maxBits;i++){
            for(int j=0;j<=maxBitNo;j++){
                if(j & (1<<i)){
                    ll curOffBitEl=j^(1<<i);

                    dp[j]=max(dp[j],dp[curOffBitEl]);
                }
            }
        }

        ll res=0;

        for(int num:nums){
            ll complement=num^maxBitNo;
            ll prod=num*dp[complement];
            res=max(res,prod);
        }

        return res;
    }
};
