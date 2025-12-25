// Approach 2 : Using Maths + Greedy + sorting
// Time : o(nlogn)
// space : o(1)
using ll=long long;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(begin(happiness),end(happiness));

        // subtracting and handling -1 initially
        int sub=0;
        for(int i=n-1;i>=0;i--){
            happiness[i]=max(0,happiness[i]-sub);

            if(sub<k) sub++;
        }


        ll res=0;
        int j=n-1;
        while(j>=0 && k>0){
            res+=happiness[j];
            k--;
            j--;
        }
        return res;
    }
};

// approach 1 : Using Brute force 
// Time : O(n^2)
// space : O(1)
using ll=long long;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(begin(happiness),end(happiness));
        ll res=0;

        for(int i=n-1;i>=0;i--){
            if(k<=0) return res;
            res+=happiness[i];

            int j=i-1;
            while(j>=0){
                if(happiness[j]>0)happiness[j]-=1;
                j--;
            }
            k--;
        }

        return res;
    }
};
