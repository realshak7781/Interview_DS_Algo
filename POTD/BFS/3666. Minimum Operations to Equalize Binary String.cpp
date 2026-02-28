// OPTIMAL APPROACH :
// TIME : O(nlogn)
// SPACE: O(n)


class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.length();

        set<int> evenSet;
        set<int> oddSet;

        for(int z=0;z<=n;z++){
            if(z&1){
                oddSet.insert(z);
            }
            else{
                evenSet.insert(z);
            }
        }

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
            int min_New_Z=curZ + k - 2*maxF;
            int max_New_Z=curZ + k - 2*minF;

            auto &targetSet=(min_New_Z & 1) ? oddSet : evenSet;

            auto it=targetSet.lower_bound(min_New_Z);

            while(it!=targetSet.end() && *it<=max_New_Z){
                int newZ=*it;

                if(!ops.count(newZ)){
                    ops[newZ]=ops[curZ]+1;
                    q.push(newZ);
                }

                it=targetSet.erase(it);
            }
        }

        return -1;
    }
};

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
