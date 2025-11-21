

// Time complexity : O(26*N)
// space : O(26)
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26,-1);
        vector<int> last(26,-1);

       for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i; 
            }
            last[idx] = i; 
        }

        int res=0;
        for(int i=0;i<26;i++){
            if(first[i]!=-1 && last[i]!=-1){
                int start=first[i];
                int end=last[i];

                if((end-start+1)<3) continue;
                vector<bool> unique(26,false);
                for(int j=start+1;j<end;j++){
                    int idx=s[j]-'a';
                    unique[idx]=true;
                }

                int count=0;
                for(int k=0;k<26;k++){
                    if(unique[k]){
                        count++;
                    }
                }

                res+=count;
            }
        }

        return res;
    }
};
