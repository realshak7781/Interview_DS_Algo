

// APPROACH 1: BRUTE FORCE
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {

        int symCnt=0;
        for(int num=low;num<=high;num++){
            string cur=to_string(num);
            if(cur.length()&1) continue;

            symCnt+=getCount(cur)==true?1:0;
        }

        return symCnt;

    }

    private:
    bool getCount(string &s){
        int size=s.length();
        int frontSum=0;
        int endSum=0;

        for(int i=0;i<size/2;i++){
            frontSum+=(s[i]-'0');
            endSum+=(s[size-i-1]-'0');
        }

        return frontSum==endSum;
    }
};
