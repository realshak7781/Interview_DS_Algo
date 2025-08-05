class Solution {
private:
vector<vector<int>> dp;
int getProfit(int day,bool buy,vector<int>& prices,int fee){
    if(day>=prices.size()){
        return 0;
    }

    if(dp[day][buy]!=-1) return dp[day][buy];
    int profit=0;
    if(buy){
        int consider=getProfit(day+1,false,prices,fee)-prices[day];
        int notConsider=getProfit(day+1,true,prices,fee);
        profit=max(consider,notConsider);
    }
    else{
        int consider=getProfit(day+1,true,prices,fee)+prices[day]-fee;
        int notConsider=getProfit(day+1,false,prices,fee);
        profit=max(consider,notConsider);
    }


    return dp[day][buy]=profit;
}    
public:
    int maxProfit(vector<int>& prices, int fee) {
        int  days=prices.size();
        dp.resize(days+1,vector<int> (2,-1));
        return getProfit(0,true,prices,fee);
    }
};
