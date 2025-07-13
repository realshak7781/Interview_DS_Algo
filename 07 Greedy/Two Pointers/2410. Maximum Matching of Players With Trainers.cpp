

// brute force : O(N*M) space : O(M)
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m=trainers.size();

        vector<bool> taken(m,false);
        int i=0;
        while(i<n){
            int index=-1;
            int minTrainerVal=INT_MAX;
            for(int j=0;j<m;j++){
                if(!taken[j] && trainers[j]<minTrainerVal && trainers[j]>=players[i]){
                    minTrainerVal=trainers[j];
                    index=j;
                }
            }
            if(index!=-1) taken[index]=true;
            i++;
        }

        int count=0;
        for(int i=0;i<m;i++){
            if(taken[i]) count++;
        }

        return count;
    }
};
