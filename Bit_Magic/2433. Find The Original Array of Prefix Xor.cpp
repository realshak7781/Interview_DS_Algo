class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // prefix array is given and we need to find the original array of size n
        int n=pref.size();
        vector<int> res(n);
        res[0]=pref[0];

        for(int i=1;i<n;i++){
            res[i]=pref[i]^pref[i-1];
        }

        // using xor property ----> a^b=c ===  b=a^c
        return res;
    }
};
