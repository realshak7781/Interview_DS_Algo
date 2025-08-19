using ll=long long;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll maxSum=0;
        ll totalSum=0;
        for(int i=0;i<prices.size();i++){
            maxSum+=(ll)(prices[i]*strategy[i]);
            totalSum+=(ll)(prices[i]);
        }
        // initial Sum calculated;
        // create a prefix Sum array :
        vector<ll> prefSum(prices.size(),0);
        prefSum[0]=(ll)prices[0];
        
        for(int i=1;i<prices.size();i++){
            prefSum[i]=prefSum[i-1]+(ll)prices[i];
        }
        
        vector<ll> prefStratSum(prices.size());
        prefStratSum[0]=(ll)(prices[0]*strategy[0]);
        for(int i=1;i<prices.size();i++){
            prefStratSum[i]=prefStratSum[i-1]+(ll)prices[i]*strategy[i];
        }
        // just do a sliding window with window size k

        int i=0;
        for(int j=0;j<prices.size();j++){
            if((j-i+1)<k)continue;

            // window size achieved
            ll mid=k/2;

            ll windowSum=prefSum[j]-(i>0?prefSum[i-1]:0);
            windowSum=windowSum-(prefSum[i+mid-1]-(i>0?prefSum[i-1]:0));

            windowSum+=(i>0?prefStratSum[i-1]:0);
            windowSum+=(prefStratSum[prices.size()-1]-prefStratSum[j]);

            maxSum=max(maxSum,windowSum);

            i++;
        }

        return maxSum;
    }
};
