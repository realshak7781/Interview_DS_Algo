
// Brute force : O(n^2)
class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();

        string res="";

        for(int i=0;i<n;i++){
            int start=i;
            for(int j=i;j<n;j++){
                if(num[j]!=num[start]) break;
                int len=j-start+1;
                if(len==3){
                    string cur=num.substr(start,len);
                    res=max(res,cur);
                    break;
                }
            }
        }

        return res;
    }
};
