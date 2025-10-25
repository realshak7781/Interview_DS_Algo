// Mathematical Approach :

class Solution {
public:
    int totalMoney(int n) {
        // Money earnt in 7 days
        int sevenDays= (7*(7+1))/2;

        int weeks=n/7;
        int remDays=n%7;

        int totalProfit=0;

        totalProfit+=(weeks*sevenDays);
        totalProfit+= 7*((weeks*(weeks-1))/2);

        // for remaining days
        for(int d=1;d<=remDays;d++){
            totalProfit+=(weeks+d);
        }
        return totalProfit;
    }
};

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
