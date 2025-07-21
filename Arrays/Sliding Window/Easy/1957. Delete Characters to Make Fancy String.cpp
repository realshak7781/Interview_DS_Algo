

// brute force approach : O(N)
// spaced : O(1)
class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();

        int i=0,j=0;
        vector<bool> take(n,true);
        int count=0;
        while(j<n){
            if(s[j]==s[i]){
                j++;
                count++;
                
                if(count>=3){
                    while(count>=3){
                        take[i]=false;
                        i++;
                        count--;
                    }
                }
            }
            else{
                count=0;
                i=j;
            }
        }

        string res="";
        for(int i=0;i<n;i++){
            if(take[i]){
                res+=s[i];
            }
        }

        return res;
    }
};
