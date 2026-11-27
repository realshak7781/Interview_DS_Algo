// time : o(logk*(n*exp(n)))

class Solution {
private:
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long countLeft(long long mid,vector<int>& coins,int n){
    int totalExpr=(1<<n)-1;

    long long correctedCount=0;
    for(int expr=1;expr<=totalExpr;expr++){
        int order=0;
        long long lcm=0;
        for(int i=0;i<n;i++){
            if(expr&(1<<i)){
                order++;

                if(lcm==0){
                    lcm=coins[i];
                }
                else{
                    lcm = (lcm / gcd(lcm, coins[i])) * coins[i];
                }
            }
        }

        if(order&1){
            correctedCount+=(mid/lcm);
        }
        else{
            // subtract
            correctedCount-=(mid/lcm);
        }
    }

    return correctedCount;
}
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size();
        long long res=0;

        int maxi=*max_element(begin(coins),end(coins));
        long long low=1;
        long long high=1LL*maxi*k;


        while(low<=high){
            long long mid=low+(high-low)/2;

            if(countLeft(mid,coins,n)>=k){
                res=1LL*mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return res;
    }
};
