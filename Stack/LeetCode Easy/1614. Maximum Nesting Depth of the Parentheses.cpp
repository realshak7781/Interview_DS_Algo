class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxi=-1;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
            }

            maxi=max(cnt,maxi);
        }

        return maxi;
    }
};
