using ll=long long;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();

        ll maxSum=0,totalStrategySum=0;
        vector<ll> pricePref(n);
        vector<ll> stratPref(n);

        for(int i=0;i<n;i++){
            totalStrategySum += strategy[i]*prices[i];
        }
        maxSum=totalStrategySum;

        pricePref[0]=prices[0];
        for(int i=1;i<n;i++){
            pricePref[i]=pricePref[i-1]+prices[i];
        }

        stratPref[0]=prices[0]*strategy[0];
        for(int i=1;i<n;i++){
            stratPref[i]=stratPref[i-1]+(prices[i]*strategy[i]);
        }

        // defining the window
        int i=0,j=k-1;

        while(j<n){
            ll windowStrategySum=stratPref[j]-(i>0 ? stratPref[i-1] : 0);
            ll remStrategySum=totalStrategySum-windowStrategySum;

            ll halfIdx=k/2;
            ll idx=i+halfIdx-1;
            ll priceSum=pricePref[j]-(idx >=0 ? pricePref[idx] : 0);
            ll newSum=priceSum+remStrategySum;

            maxSum=max(maxSum,newSum);
            i++;
            j++;
        }

        return maxSum;
    }
};
