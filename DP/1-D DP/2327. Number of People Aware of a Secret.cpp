const int MOD = 1e9 + 7;
class Solution {
private:
    vector<int> dp;
    // int solve(int day,int delay,int forget){
    //     // this function tells us the number of extra people that came to
    //     know about the secret that particular day if(day<=0) return 0;
    //     if(day==1) return 1;

    //     if(dp[day]!=-1) return dp[day];
    //     int res=0;
    //     for(int d=day-forget+1;d<=(day-delay);d++){
    //         if(d>=0)res=(res+solve(d,delay,forget))%MOD;
    //     }

    //     return dp[day]=res;
    // }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        dp.resize(n + 1, 0);
        dp[1] = 1;

        for (int day =2; day <= n; day++) {
            int res=0;
            for (int d = day - forget + 1; d <= (day - delay); d++) {
                if (d >= 0)
                    res = (res + dp[d]) % MOD;
            }
            dp[day]=res;
        }


        int totalCount = 0;
        for (int d = n - forget + 1; d <= n; d++) {
            totalCount = (totalCount + dp[d]) % MOD;
        }

        return totalCount;
    }
};
