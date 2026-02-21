class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();

        int cntZero=0;
        int cntOne=0;
        int i=0;

        int resCnt=0;
        while(i<n){
            char cur=s[i];
            int j=i;
            int curCnt=0;
            while(j<n && s[j]==cur){
                j++;
                curCnt++;
            }

            // the current character has a streak of curCnt
            // if its a zero it needs previous 1s 
            // if its 1 it needs previous zeros

            if(cur=='0'){
                resCnt+=min(curCnt,cntOne);
                cntZero=curCnt;
                cntOne=0;
            }
            else{
                resCnt+=min(curCnt,cntZero);
                cntOne=curCnt;
                cntZero=0;
            }

            i=j;
        }

        return resCnt;
    }
};
