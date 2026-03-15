
// Using optimal approach by converting string s to decimals
// Time : o(len + maxVal)
// space : o(n)
class Solution {
private:
int findPower(int a,int b){
    if(b==0){
        return 1;
    }
    int half=findPower(a,b/2);
    int res=half*half;

    if(b&1){
        res=a*res;
    }
    return res;
}


int getValFromString(string &s){
    int len=s.length();

    int val=0;
    int mul=1;
    for(int i=len-1;i>=0;i--){
        val=val + (s[i]-'0')*mul;
        mul*=2;
    }
    return val;
}

string getStringFromVal(int val,int len){

    string res="";
    while(val>0){
        int dig=val%2;
        res+=(dig+'0');
        val/=2;
    }

    // append zeroes
    int n=res.length();
    for(int i=1;i<=(len-n);i++){
        res+='0';
    }

    reverse(res.begin(),res.end());

    return res;
}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int len=nums.size();
        unordered_set<int> availVal;
        int maxVal=findPower(2,len)-1;

        for(string &s:nums){
            availVal.insert(getValFromString(s));
        }

        for(int res=0;res<=maxVal;res++){
            if(!availVal.count(res)){
                return getStringFromVal(res,len);
            }
        }

        return "";
    }
};

// USING BRUTE FORCE APPROACH :
// BACKTRACKING
// TIME : EXPONENTIAL
// SPACE : O(N)
class Solution {
private:
unordered_set<string> seen;
string res="";

void solve(string &cur,int idx,int len){
    if(idx>=len){
        if(res.empty() && !seen.count(cur)){
            res=cur;
        }
        return;
    }

    // pick 1
    cur+='1';
    solve(cur,idx+1,len);
    cur.pop_back();
    // pick 0
    cur+='0';
    solve(cur,idx+1,len);

    cur.pop_back();
}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        seen.insert(begin(nums),end(nums));
        int len=nums.size();
        string cur="";
        solve(cur,0,len);
        return res;
    }
};
