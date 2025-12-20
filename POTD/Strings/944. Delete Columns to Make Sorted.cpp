class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int stringSize=strs[0].size();

        int res=0;
        for(int i=0;i<stringSize;i++){
            char prev='#';
            for(string s:strs){
                char cur=s[i];
                if(prev!='#'){
                    if(prev>cur){
                        res++;
                        break;
                    }
                }
                prev=cur;
            }
        }

        return res;
    }
};
