class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res="";

        while(a>0 || b>0){
            int i=res.length()-1;
            if(res.length()>=2 && res[i]==res[i-1]){
                if(res[i]=='a'){
                    res+='b';
                    b--;
                }
                else{
                    res+='a';
                    a--;
                }
            }
            else{
               
               if (a > b) {
                    res += 'a';
                    a--;
                } 
                else if (b > a) {
                    res += 'b';
                    b--;
                }
                else{

                    if(a>0){
                        res+='a';
                        a--;
                    }
                    else if(b>0){
                        res+='b';
                        b--;
                    }
                }
                
            }
        }

        return res;
    }
};
