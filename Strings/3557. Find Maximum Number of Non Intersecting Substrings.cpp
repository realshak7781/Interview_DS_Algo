class Solution {
public:
    int maxSubstrings(string word) {
        int n=word.length();
        vector<int> vis(26,-1);

        int resCount=0;
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';

            if(vis[idx]!=-1 && (i-vis[idx]+1)>=4){
                resCount++;
                for(int i=0;i<26;i++){
                    vis[i]=-1;
                }
            }
            else{
                if(vis[idx]==-1){
                    vis[idx]=i;
                }
            }
        }

        return resCount;
    }
};
