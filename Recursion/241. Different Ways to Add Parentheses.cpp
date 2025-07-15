// time : O(n*2^n)
// space : o(2^n)
class Solution {
private: 
vector<int> solve(int start,int end,string &s){
    vector<int> res;

    for(int i=start;i<=end;i++){
        char cur=s[i];
        if(cur=='+'|| cur=='-'|| cur=='*'){
            vector<int> left=solve(start,i-1,s);
            vector<int> right=solve(i+1,end,s);

            for(int x:left){
                for(int y:right){
                    if(cur=='*'){
                        res.push_back(x*y);
                    }
                    else if(cur=='-'){
                        res.push_back(x-y);
                    }
                    else{
                        res.push_back(x+y);
                    }
                }
            }
        }
    }

    if(res.empty()){
        res.push_back(stoi(s.substr(start,end-start+1)));
    }
    return res;
}  
public:
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.length();

        return solve(0,n-1,expression);
    }
};
