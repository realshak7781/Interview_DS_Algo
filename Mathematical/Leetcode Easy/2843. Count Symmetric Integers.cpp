

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



// APPROACH 2 : MATHEMATICAL
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        // as per constraints 
        //  we can form only two len sym numbers and 4 len sym numbers;

        int symCnt=0;
        for(int num=low;num<=high;num++){
            if(num>10 && num<=99 && num%11==0){
                symCnt++;
            }
            else if(num>1000){
                // 4 digit numbers : check separately
                int first=num/1000;
                int second=(num/100)%10;
                int startSum=first+second;

                int third=(num/10)%10;
                int fourth=num%10;

                int endSum=third+fourth;

                if(startSum==endSum) symCnt++;
            }
        }

        return symCnt;
    }
};
