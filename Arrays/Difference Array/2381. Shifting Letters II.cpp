using ll=long long;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
         int n=s.length();

        vector<ll> diff(n+1,0);

        for(auto it:shifts){
            int l=it[0];
            int r=it[1];
            int dir=it[2];
            int shiftVal=1;

            if(dir==0){
                shiftVal=-1;
            }

            diff[l]+=shiftVal;
            diff[r+1]-=shiftVal;
        }

        vector<ll> prefChange(n,0);
        prefChange[0]=diff[0];

        for(int i=1;i<n;i++){
            prefChange[i]=prefChange[i-1]+diff[i];
        }


        for(int i=0;i<n;i++){
            int curIdx=s[i]-'a';
            int shift=prefChange[i];

            int newIdx=((curIdx+shift)%26+26)%26;

            s[i]='a'+newIdx;
        }

        return s;
    }
};
