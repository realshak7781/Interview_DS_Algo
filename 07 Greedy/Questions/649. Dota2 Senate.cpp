// optimal : USING TWO QUEUES


class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.length();

        queue<int> queR;
        queue<int> queD;

        for(int i=0;i<n;i++){
            if(senate[i]=='D'){
                queD.push(i);
            }else{
                queR.push(i);
            }
        }


        while(!queR.empty() && !queD.empty()){
            int RIdx=queR.front();queR.pop();
            int DIdx=queD.front();queD.pop();

            if(RIdx<DIdx){
                queR.push(RIdx+n);
            }
            else{
                queD.push(DIdx+n);
            }
        }

        return queD.empty()? "Radiant":"Dire";
    }
};


// brute force: O(n^2)
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        vector<bool> rights(n,true);

        while (true) {

            int countR = 0, countD = 0;

            for (int i = 0; i < n; i++) {
                if (!rights[i])
                    continue;

                if (senate[i] == 'R')
                    countR++;
                else
                    countD++;
            }

            if (countR == 0)
                return "Dire";
            if (countD == 0)
                return "Radiant";

            for (int i = 0; i < n; i++) {
                char cur = senate[i];
                if (!rights[i])
                    continue;
                bool banned = false;
                for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
                    if (rights[j] && senate[j] != cur) {
                        rights[j] = false;
                        banned = true;
                        break;
                    }
                }
            }
        }

        return "";
    }
};
