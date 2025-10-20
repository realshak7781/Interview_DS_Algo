class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res=0;

        for(string s:operations){
            bool increase=false;

            for(int i=0;i<3;i++){
                if(s[i]=='+'){
                    increase=true;
                    break;
                }
            }

            if(increase){
                res=res+1;
            }
            else{
                res=res-1;
            }
        }

        return res;
    }
};
