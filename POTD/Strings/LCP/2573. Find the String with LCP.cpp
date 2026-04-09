
// Not   a hard question ,easiest question
class Solution {
vector<vector<int>> createLcp(string &s){
    int n=s.length();
    vector<vector<int>> newLcp(n,vector<int>(n,0));

    // fill last column
    // fill last row
    for(int i=0;i<n;i++){
        if(s[i]==s[n-1]){
            newLcp[i][n-1]=1;
            newLcp[n-1][i]=1;
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(s[i]==s[j]){
                newLcp[i][j]=1+newLcp[i+1][j+1];
            }
            else{
                newLcp[i][j]=0;
            }
        }
    }

    return newLcp;
}
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();

        string word="";
        for(int i=0;i<n;i++){
            word+="$";
        }
        
        for(int i=0;i<n;i++){
            int j=0;
            vector<bool> forbidden(26,false);
            while(j<i){
                int charIdx=word[j]-'a';
                if(lcp[i][j]==0){
                    forbidden[charIdx]=true;
                }
                j++;
            }

            for(int k=0;k<26;k++){
                if(forbidden[k]==false){
                    word[i]='a'+k;
                    break;
                }
            }

            if(word[i]=='$') return "";
        }


        vector<vector<int>> newLcp=createLcp(word);

        // now check if we have new and old lcp arrays same
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(lcp[i][j]!=newLcp[i][j]) return "";
            }
        }

        return word;
    }
};
