// The worst-case theoretical upper bound is O(N^2) if K is unbounded, because calculating permutations takes O(n) steps across the n positions. 
// However, because we clamp and break early once ways >= k, the permutation count saturates in at most O(logk) steps. 
//   Since k fits in a standard integer, this cap bounds the inner work to a small constant, giving an effective runtime of O(n) in practice.


class Solution {
private:
int ncr(int n,int r,int k){
    int ways=1;

    for(int i=1;i<=r;i++){
        ways*=(n-r+i);
        ways/=i;

        if(ways>=k) return k;
    }

    return ways;
}
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length(); 
        if(n==1){
            // handling the edge cases
            return (k>1) ? ""  : s;
        }
        
        int halfLen = n / 2;

        vector<int> freq(26, 0);
        for (int i = 0; i < halfLen; i++) {
            freq[s[i] - 'a'] += 1;
        }

        string firstHalf = "";

        for (int pos = 0; pos < halfLen; pos++) {
            bool placed = false;

            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    freq[i] -= 1;

                    int letters = 0;
                    long long ways = 1;

                    for (int j = 0; j < 26; j++)
                        letters += freq[j];

                    for (int m = 0; m < 26; m++) {
                        if (freq[m] > 0) {
                            ways *= ncr(letters, freq[m], k);
                            letters -= freq[m];
                            if (ways >= k)
                                break;
                        }
                    }


                    if(ways>=k){
                        placed=true;
                        char ch='a'+ i;
                        firstHalf+=ch;
                        break;
                    }

                    freq[i]+=1;
                    k=k-ways;
                }
            }

            if(!placed){
                return "";
            }
        }

        string secondHalf=firstHalf;
        if(n&1){
            firstHalf+=s[halfLen];
        }

        reverse(begin(secondHalf),end(secondHalf));
        string res=firstHalf+secondHalf;

        return res;
    }
};
