// T.C : o(N) (EACH NUMBER IS VISITED ONCE)
// S.C : o(LOG10(N)) RECURSION CALL STACK + O(N)(RES)

class Solution {
private:
void dfs(int root,vector<int>&res,int n){
    res.push_back(root);

    for(int i=0;i<=9;i++){
        int next=root*10+i;
        if(next>n) break;
        dfs(next,res,n);
    }
}    
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for(int i=1;i<=9;i++){
            if(i<=n)dfs(i,res,n);
        }

        return res;
    }
};
