


// Approach 2 : Using No extra space
class Solution {
public:
    int minimumDeletions(string s) {
        // trying to keep all the a's to the left and all the b's to the right
        // at  any point we will count how many a's we have on the right side
        // we will also count how many b's we have on left side
        // the deletions will be the sum of these two

        int aOnRight=0;
        int bOnLeft=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') aOnRight++;
        } 

        int minDels=1e9;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') aOnRight--;

            int delsReq=aOnRight+bOnLeft;

            minDels=min(minDels,delsReq);
            if(s[i]=='b') bOnLeft++;
        }

        return minDels==1e9 ? 0 : minDels;
    }
};
