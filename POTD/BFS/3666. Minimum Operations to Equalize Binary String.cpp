// BRUTE FORCE : USING MATHEMATICS + BFS BASED APPROACH : (HATS OFF TO MAZHAR MIK FOR TEACHING THIS INCREDIBLE SOLUTION)
// TIME : O(V+E) = O(N+ N*k)
// SPACE : O(N) + O(N)

class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.length();
        unordered_map<int,int> ops;

        queue<int> q;
        int curZeroesCount=0;
        for(char c:s){
            if(c=='0'){
                curZeroesCount++;
            }
        }

        q.push(curZeroesCount);
        ops[curZeroesCount]=0;

        while(!q.empty()){
            int curZ=q.front();
            q.pop();

            if(curZ==0) return ops[curZ];

            int minF=max(0,k-n+curZ);
            int maxF=min(k,curZ);

            for(int f=minF;f<=maxF;f++){
                int newZ=curZ+k-2*f;

                if(ops.count(newZ)) continue;

                ops[newZ]=ops[curZ]+1;
                q.push(newZ);
            }
        }

        return -1;
    }
};
