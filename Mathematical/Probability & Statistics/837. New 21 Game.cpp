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
