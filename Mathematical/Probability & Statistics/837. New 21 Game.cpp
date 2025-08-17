// optimal:
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> P(n+1,0.0);
        P[0]=1.0;

        double probSum=(k==0)?0.0:1.0;

        for(int i=1;i<=n;i++){
            P[i]=probSum/maxPts;
            if(i<k){
                probSum+=P[i];
            }
            if((i-maxPts)>=0 && (i-maxPts)<k){
                probSum-=P[i-maxPts];
            }
        }

        double res=0.0;

        for(int i=k;i<=n;i++){
            res+=P[i];
        }

        return res;

    }
};

// Brute force :
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> P(n+1,0.0);

        // p[i]= probability to score i points'
        P[0]=1.00000;

        for(int i=1;i<=n;i++){
            for(int card=1;card<=maxPts;card++){
                
                if((i-card)>=0 && (i-card)<k){
                    P[i]+=P[i-card] / maxPts;
                }
            }
        }

        double res=accumulate(begin(P)+k,end(P),0.0);

        return res;
    }
};
