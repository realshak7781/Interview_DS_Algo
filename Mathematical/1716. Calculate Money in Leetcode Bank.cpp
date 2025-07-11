
// O(6)~ o(1)
class Solution {
public:
    int totalMoney(int n) {
       if(n<=7){
         return n*(n+1)/2;
       }

       int items=n/7;
       int first=28;
       int last=28+(items-1)*7;
    //     the days form and AP: 28 ,35, and so on
       int arithmeticSum= items*(first+last)/2;

       int remDays=n%7;

       int mondayPrice=items+1;
       int finalRemMoney=0;

       for(int day=1;day<=remDays;day++){
            finalRemMoney+=mondayPrice;
            mondayPrice++;
       }

       return finalRemMoney+arithmeticSum;
    }
};
// BRUTE FORCE: O(N)
class Solution {
public:
    int totalMoney(int n) {
        int totalMoney=0;
        int start=0;
        int prevMonday=0;
        for(int i=1;i<=n;i++){
            if(i%7==1){
                // new Monday reached
                start=prevMonday+1;
                prevMonday+=1;
            }
            else{
                start=start+1;
            }
            totalMoney+=start;
        }

        return totalMoney;
    }
};
