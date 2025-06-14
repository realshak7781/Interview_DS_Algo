class Solution {
private:
int bitMaskApproach(string allowed, vector<string>& words){
    int allwMask=0;
    for(char c:allowed){
        int pos=c-'a';
        allwMask|=(1<<pos);
    }

    int count=0;
    for(string &s:words){
        int sMask=0;

        for(char c:s){
            int pos=c-'a';
            sMask|=(1<<pos);
        }

        if((sMask|allwMask)==allwMask) count++;
    }

    return count;
}    
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // unordered_set<char> allw;
        // for(char c:allowed){
        //     allw.insert(c);
        // }

        // int count=0;
        // for(string &s:words){
        //     bool isGood=true;

        //     for(char c:s){
        //         if(!allw.count(c)){
        //             isGood=false;
        //             break;
        //         }
        //     }

        //     if(isGood) count++;
        // }

        // return count;

        return bitMaskApproach(allowed,words);
    }
};
