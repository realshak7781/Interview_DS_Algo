class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(begin(deadends),end(deadends));

        unordered_set<string> seen;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        seen.insert("0000");

        while(!q.empty()){
            string cur=q.front().first;
            int steps=q.front().second;

            q.pop();

            if(cur==target) return steps;
            if(dead.count(cur)) continue;


            for(int i=0;i<4;i++){
                char org=cur[i];
                int orgVal=org-'0';
                int nextVal=(orgVal+1)%10;
                int prevVal=(orgVal-1+10)%10;

                char nextChar=nextVal+'0';
                cur[i]=nextChar;

                if(!seen.count(cur)){
                    q.push({cur,steps+1});
                    seen.insert(cur);
                }
                char prevChar=prevVal+'0';
                cur[i]=prevChar;
                if(!seen.count(cur)){
                    q.push({cur,steps+1});
                    seen.insert(cur);
                }

                cur[i]=org;
            }
        }


        return -1;
    }
};
