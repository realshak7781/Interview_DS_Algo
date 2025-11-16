const int mod=1e9+7;
class Solution {
private:
int n;

int bruteForce(string &s){
      int totalCount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') continue;
            // taking each index if it has a '1' as the starting point of the subarray and expanding

            int count=0;
            int j=i;

            while(j<n && s[j]=='1'){
                count=(count+1)%mod;
                j++;
            }

            totalCount=(totalCount+count)%mod;
        }

        return totalCount;
}

int optimal(string &s){
    int totalCount=0;

    for(int i=0;i<n;i++){
        if(s[i]=='0') continue;

        int j=i;
        while(j<n && s[j]=='1'){
            j++;
        }
        int len=j-i;
        int totalSubs = (((long long)len % mod * (len + 1) % mod) / 2) % mod;
        totalCount=(totalCount+totalSubs)%mod;
        i=j-1;
    }

    return totalCount;
}
public:
    int numSub(string s) {
        n=s.length();

        return optimal(s);
    }
};
