

// CLASSIC TWO POINTER APPROACH WITH CAREFUL IF ELSE CONDITIONS
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        if(n==0) return 0;
        sort(tokens.begin(),tokens.end());

        int low=0,high=n-1,maxScore=INT_MIN;
        int score=0;
        while(low<=high){
            if(low==high){
                // last token or only token, try to play face up ,if not able return score
                if(power>=tokens[low]){
                    score+=1;
                    power-=tokens[low];
                    low++;
                }
                else{
                    return score;
                }
            }
            else{
                // first try face up
                if(power>=tokens[low]){
                    power-=tokens[low];
                    low++;
                    score+=1;
                }else{
                    // face down logic here
                    if(score<=0) return score;
                    score-=1;
                    power+=tokens[high];
                    high--;
                }
            }

            maxScore=max(maxScore,score);
        }

        return maxScore;
    }
};
