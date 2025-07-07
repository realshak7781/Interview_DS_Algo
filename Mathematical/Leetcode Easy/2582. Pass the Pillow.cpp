
// MATHEMATICAL :O(1) APPROACH
class Solution {
public:
    int passThePillow(int n, int time) {
        // TO REACH N WE NEED N-1 SECONDS

        int res=1;
        int tripTime=n-1;

        if(time<=tripTime){
            res+=time;
        }
        else{
            int trips=time/tripTime;
            int rem=time%tripTime;
            if(trips&1){
                res=n-rem;
            }
            else{
                res+=rem;
            }
        }

        return res;
    }
};

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
