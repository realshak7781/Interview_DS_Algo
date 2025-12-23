// approach 1: using map + bfs 
// time : O(meetings) + O(time * (meetings + (persons+meetings)))
// space : O(meetings + person)
using p=pair<int,int>;
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<p>> timeMeetings;

        for(auto &it:meetings){
            int t=it[2];
            int u=it[0];
            int v=it[1];
            timeMeetings[t].push_back({u,v});
        }
        vector<bool> knowsSecret(n,false);
        knowsSecret[0]=true;
        knowsSecret[firstPerson]=true;


        for(auto &it:timeMeetings){
            int time=it.first;

            unordered_map<int,vector<int>> adj;
            queue<int> q;
            unordered_set<int> seen;
            // populate the adjacency list;
            for(auto &p:it.second){
                int u=p.first;
                int v=p.second;
                adj[u].push_back(v);
                adj[v].push_back(u);

                if(knowsSecret[u] && seen.find(u)==seen.end()){
                    q.push(u);
                    seen.insert(u);
                }

                if(knowsSecret[v] && seen.find(v)==seen.end()){
                    q.push(v);
                    seen.insert(v);
                }
            }

            // do bfs
            while(!q.empty()){
                int p=q.front();
                q.pop();


                for(auto &neigh:adj[p]){
                    if(knowsSecret[neigh]==false){
                        knowsSecret[neigh]=true;
                        q.push(neigh);
                    }
                }
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(knowsSecret[i]==true) res.push_back(i);
        }

        return res;
    }
};

// approach 4: using union find
class disjointSet{
    private:
    vector<int> parent;
    vector<int> rank;
    public:

    disjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findParent(int node){
        if(node==parent[node]) return node;

        return parent[node]=findParent(parent[node]);
    }


    void unionByRank(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv) return;

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    void reset(int node){
        parent[node]=node;
        rank[node]=0;
    }

};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        disjointSet ds(n);


        sort(meetings.begin(),meetings.end(),[](const vector<int> &a,const vector<int>&b){
            return a[2] < b[2];
        });

        ds.unionByRank(0,firstPerson);
        int i=0;
        while(i<meetings.size()){
            int currentTime=meetings[i][2];
            int j=i;

            vector<int> currentBatch;
            while(j<meetings.size() && meetings[j][2]==currentTime){
                int u=meetings[j][0];
                int v=meetings[j][1];
                ds.unionByRank(u,v);

                j++;
                currentBatch.push_back(u);
                currentBatch.push_back(v);
            }

            for(int p:currentBatch){
                if(ds.findParent(p)!=ds.findParent(0)){
                    ds.reset(p);
                }
            }

            i=j;
        }


        vector<int> res;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==ds.findParent(0)){
                res.push_back(i);
            }
        }

        return res;
    }
};
