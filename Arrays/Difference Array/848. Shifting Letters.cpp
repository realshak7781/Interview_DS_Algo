// optimal
using ll=long long;
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();

        vector<ll> diff(n+1,0);

        for(int i=0;i<n;i++){
            int l=0;
            int r=i;
            int shiftVal=shifts[i];

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
            int newIdx=(curIdx+prefChange[i])%26;

            s[i]='a'+newIdx;
        }

        return s;
    }
};


// Brute Force : 
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        int m=shifts.size();
        for(int i=0;i<m;i++){
            int shiftCount=i+1;
            int shiftVal=shifts[i];

            for(int j=0;j<min(shiftCount,n);j++){
                int curIdx=s[j]-'a';
                int newIdx=(curIdx+shiftVal)%26;

                s[j]='a'+newIdx;
            }
        }

        return s;
    }
};
