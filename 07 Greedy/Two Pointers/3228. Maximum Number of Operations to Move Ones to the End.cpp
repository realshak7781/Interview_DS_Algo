class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int endIdx=n-1;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                endIdx--;
            }
            else{
                break;
            }
        }

        int ops=0;
        int i=0;
        int totalCnt=0;
        while(i<=endIdx){
            if(s[i]=='0') {
                i++;
                continue;
            }

            // foudn 1 : count continuous 1s
            int j=i;
            int cnt=0;
            while(s[j]=='1'){
                cnt++;
                j++;
            }
            i=j;
            totalCnt+=cnt;

            ops+=totalCnt;
        }

        return ops;
    }
};
