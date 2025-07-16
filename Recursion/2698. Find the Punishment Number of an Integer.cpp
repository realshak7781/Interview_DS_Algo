// recursion+memoization:
using ll=long long;
class Solution {
private:
vector<vector<ll>> dp;
bool check(int start,int end,string &s,ll target,ll temp){
    if(start>end){
        return temp==target;
    }

    if(temp>target) return false;

    if(dp[start][temp]!=-1) return dp[start][temp];

    bool checkRes=false;
    for(int i=start;i<=end;i++){
        ll val=stoll(s.substr(start,i-start+1));
        temp=temp+val;
        if(check(i+1,end,s,target,temp)){
            checkRes=true;
            break;
        }
        temp=temp-val;
    }

    return dp[start][temp]=checkRes;
} 
public:
    int punishmentNumber(int n) {
        int sum=0;

        for(int i=1;i<=n;i++){
            // O(n)
            ll num=i*i;
            string cur=to_string(num);
            // no of digit in num: log(i*i) worst case: log(n*n),lets call it L;
            ll temp=0;
            dp.clear();
            dp=vector<vector<ll>>(cur.size()+1,vector<ll>(i+1,-1));
            if(check(0,cur.length()-1,cur,i,temp)){
                // check function splits,and then not split at L-1 positions ,two choices, time(check)=2^(L-1)~ 2^L

                sum+=i*i;
            }
            // overall time : O(n*2^L)=O(n*2^log(n^2))= O(n*n^log(2^2)) : base is 10  ~ O(n^2)
            // space is recusive call stack :O(L): O(log(n^2));
        }

        return sum;
    }
};

// BRUTE FORCE:
using ll=long long;
class Solution {
private:
bool check(int start,int end,string &s,ll target,ll temp){
    if(start>end){
        return temp==target;
    }

    for(int i=start;i<=end;i++){
        ll val=stoll(s.substr(start,i-start+1));
        temp=temp+val;
        if(check(i+1,end,s,target,temp)) return true;
        temp=temp-val;
    }

    return false;
} 
public:
    int punishmentNumber(int n) {
        int sum=0;

        for(int i=1;i<=n;i++){
            // O(n)
            ll num=i*i;
            string cur=to_string(num);
            // no of digit in num: log(i*i) worst case: log(n*n),lets call it L;
            ll temp=0;
            if(check(0,cur.length()-1,cur,i,temp)){
                // check function splits,and then not split at L-1 positions ,two choices, time(check)=2^(L-1)~ 2^L

                sum+=i*i;
            }
            // overall time : O(n*2^L)=O(n*2^log(n^2))= O(n*n^log(2^2)) : base is 10  ~ O(n^2)
            // space is recusive call stack :O(L): O(log(n^2));
        }

        return sum;
    }
};
