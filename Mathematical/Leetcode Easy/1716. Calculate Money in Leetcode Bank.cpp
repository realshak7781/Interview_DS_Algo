

// Brute force : A for loop
class Solution {
public:
    int totalMoney(int n) {
        // Money earnt in 7 days
        int sevenDays= (7*(7+1))/2;
        int prevStart=0;
        int start=0;
        int totalProfit=0;
        for(int i=1;i<=n;i++){
            if(i%7==1){
                start=prevStart;
                prevStart++;
            }
            ++start;
            totalProfit+=start;
        }

        return totalProfit;
    }
};
