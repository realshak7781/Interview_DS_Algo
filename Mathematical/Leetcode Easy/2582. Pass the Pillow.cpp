

// BRUTE FORCE : O(T)
class Solution {
public:
    int passThePillow(int n, int time) {
        int res=-1;
        int hold=1;
        bool forward=true;
        for(int t=1;t<=time;t++){
            if(hold==n){
                forward=false;
            }
            else if(hold==1){
                forward=true;
            }
            
            if(forward){
                hold++;
            }
            else{
                hold--;
            }

            res=hold;
        }

        return res;
    }
};
