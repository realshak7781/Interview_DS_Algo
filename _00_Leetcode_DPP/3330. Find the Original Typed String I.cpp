class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.length();
        int left=0,right=0;

        int org=1;
        int count=0;
        while(right<n){
            if(word[left]==word[right]){
                count++;
                right++;
                if(right==n){
                    org+=(count-1);
                }
            }
            else{
                org+=(count-1);
                count=0;
                left=right;
            }
        }

        return org;
    }
};
