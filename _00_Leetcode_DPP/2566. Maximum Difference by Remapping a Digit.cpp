class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        int n=s.length();

        char toChangeForMax;
        for(char c:s){
            int val=c-'0';
            if(val!=9){
                toChangeForMax=c;
                break;
            }
        }

        int maxi;
        for(int i=0;i<n;i++){
            if(s[i]==toChangeForMax){
                s[i]='9';
            }
        }
        maxi=stoi(s);

        // for min element
        s=to_string(num);
        char toChangeforMin;
        for(char c:s){
            int val=c-'0';

            if(val!=0){
                toChangeforMin=c;
                break;
            }
        }

        for(int i=0;i<n;i++){
            if(s[i]==toChangeforMin){
                s[i]='0';
            }
        }

        int mini=stoi(s);

        return maxi-mini;
    }
};
