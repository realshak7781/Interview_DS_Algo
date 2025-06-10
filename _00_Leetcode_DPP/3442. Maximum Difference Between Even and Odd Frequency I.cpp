class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }

        int maxOddCnt=INT_MIN;
        int minEvenCnt=INT_MAX;

        for(auto &it:freq){
            int count=it.second;
            if(count&1){
                maxOddCnt=max(maxOddCnt,count);
            }
            else{
                minEvenCnt=min(minEvenCnt,count);
            }
        }

        int diff=maxOddCnt-minEvenCnt;
        return diff;
    }
};
