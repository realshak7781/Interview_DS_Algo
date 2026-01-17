class Solution {
public:
    int countTriples(int n) {
        int count=0;

        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                int cSq=a*a + b*b;
                int c=sqrt(cSq);

                if(c*c==cSq && c<=n){
                    count+=2;
                }
            }
        }

        return count;
    }
};
