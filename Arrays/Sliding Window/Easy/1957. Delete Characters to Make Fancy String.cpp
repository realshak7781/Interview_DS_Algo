// better approach :
class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();

        vector<int> freq(26,0);
        string res="";

        for(int i=0;i<s.length();i++){
            if(i==0){
                // first char
                freq[s[i]-'a']++;
                res+=s[i];
            }
            else{
                char cur=s[i];
                char prev=res.back();
                res+=cur;
                if(cur==prev){
                    freq[cur-'a']++;
                    int count=freq[cur-'a'];
                    if(count>=3){
                        // cur char forms three cons series
                        res.pop_back();
                        freq[cur-'a']--;
                    }
                }
                else{
                    freq[cur-'a']++;
                    freq[prev-'a']=0;
                }
                
            }
        }

        return res;
    }
};

// brute force approach : O(N)
// spaced : O(N)
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
