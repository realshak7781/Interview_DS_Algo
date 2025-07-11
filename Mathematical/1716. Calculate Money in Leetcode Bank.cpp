
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
