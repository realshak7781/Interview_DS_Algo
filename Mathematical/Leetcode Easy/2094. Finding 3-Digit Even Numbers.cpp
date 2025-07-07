

// BRUTE FORCE APPROACH:
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();

        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(digits[i]==0) continue;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j || j==k || i==k) continue;

                    int num=100*digits[i]+10*digits[j]+1*digits[k];

                    if(num%2==0)st.insert(num);
                }
            }
        }

        vector<int> res(st.begin(),st.end());
        sort(res.begin(),res.end());


        return res;
    }
};
