class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        int remCharCount=(n%k);
        int fillCount=0;
        if(remCharCount!=0){
            fillCount=k-remCharCount;
        }

        int i=0;
        int start=0;
        vector<string> res;
        while(i<n){
            if((i-start+1)==k){
                res.push_back(s.substr(start,k));
                i++;
                start=i;
                continue;
            }

            i++;
        }

        if(fillCount!=0){
            int lastIndex=(n/k) *k;

            string last="";
            for(int i=lastIndex;i<n;i++){
                last+=s[i];
            }

            while(fillCount>0){
                last+=fill;
                fillCount--;
            }

            res.push_back(last);
        }

        return res;
    }
};
