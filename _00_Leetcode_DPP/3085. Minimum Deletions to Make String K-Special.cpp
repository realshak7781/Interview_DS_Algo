class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        int n=word.length();
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }

        int miniDelt=INT_MAX;
        for(int i=0;i<26;i++){
            int freqi=freq[i];
            if(freqi==0) continue;
            // char doesnt exist in word;
            int deletion=0;
            for(int j=0;j<26;j++){
                if(j==i) continue;
                if(freq[j]==0) continue;

                if(freq[j]<freqi){
                    deletion+=freq[j];
                }
                else if(freq[j]>(freqi+k)){
                    deletion+= abs(freq[j]-freqi-k);
                }
            }

            miniDelt=min(deletion,miniDelt);
        }

        return miniDelt;
    }
};
