class Solution {
public:
    int minOperations(string s) {
        int n=s.length();

        sort(begin(s),end(s));

        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]!='a'){
                temp+=s[i];
            }
        }

       if(temp.length()==0) return 0;
       
        int ops=0;
        int i=1;
        while(i<temp.length()){
            ops+=(temp[i]-temp[i-1]);
            i++;
        }
        char last=temp[temp.length()-1];
        int zSteps='z'-last;

        ops+=(zSteps+1);
        return ops;
    }
};
