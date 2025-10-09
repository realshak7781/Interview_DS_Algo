using ll=long long;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();

        vector<ll> finishTime(n,0);
        // finish time of wizard i to finish the current potion 

        // for the first potion
        for(int i=0;i<n;i++){
            // let the wizards finish the first potion : mana[0];
            if(i==0){
                finishTime[i]=mana[0]*skill[i];
            }
            else{
                finishTime[i]=finishTime[i-1]+mana[0]*skill[i];
            } 
        }

        for(int j=1;j<m;j++){

            finishTime[0]=finishTime[0] + mana[j]*skill[0];
            
            for(int i=1;i<n;i++){
                finishTime[i]=max(finishTime[i],finishTime[i-1]) + mana[j]*skill[i];
            }


            // coorrection of finish time to maintain synchornization:
            for(int i=n-2;i>=0;i--){
                finishTime[i]=finishTime[i+1]-mana[j]*skill[i+1];
            }
        }

        ll res=finishTime[n-1];

        return res;
    }
};
