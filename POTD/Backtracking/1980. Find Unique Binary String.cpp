

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
