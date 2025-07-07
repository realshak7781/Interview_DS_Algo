
// MATHEMATICAL
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;

        for(int dig:digits) mp[dig]++;

        vector<int> res;

        for(int i=1;i<=9;i++){
            if(mp[i]==0) continue;
            mp[i]--;

            for(int j=0;j<=9;j++){
                if(mp[j]==0) continue;
                mp[j]--;

                for(int k=0;k<=8;k+=2){
                    if(mp[k]==0) continue;
                    mp[k]--;

                    int num=i*100 +j*10+k;
                    res.push_back(num);

                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }


        return res;
    }
};

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
