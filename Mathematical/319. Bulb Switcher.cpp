class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0 || n==1) return n;

        return sqrt(n);
    }
};


// T.C: O(N^2)
// S.C : O(N)
class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0 || n==1) return n;

       vector<int> bulbs(n+1,1);

       for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            bulbs[j]=1-bulbs[j];
        }
       }

       int count=0;

       for(int i=1;i<=n;i++){
        if(bulbs[i]==1) count++;
       }


       return count;
    }
};
