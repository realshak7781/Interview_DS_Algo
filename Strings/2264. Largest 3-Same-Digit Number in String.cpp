



// Optimal approach : O(n) time and O(3)*n space at worst case
class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();

        string res="";
        int k=3;
        int i=0;
        int j=0;

        while(j<n){
            if(num[j]!=num[i]){
                i=j;
                continue;
            }

            if((j-i+1)==3){
                string sub=num.substr(i,3);
                res=max(res,sub);
                i++;
            }
            j++;
        }
        return res;
    }
};

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
