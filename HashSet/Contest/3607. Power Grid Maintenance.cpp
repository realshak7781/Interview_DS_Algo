class disjointSet{
    private:
    vector<int> rank,parent;
    public:

    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }


    int findUPar(int node){
        if(node==parent[node]) return node;

        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int pu=findUPar(u);
        int pv=findUPar(v);

        if(pu==pv) return;

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pu]=pv;
            rank[pv]+=1;
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        disjointSet ds(c);

        for(auto it:connections){
            int u=it[0];
            int v=it[1];

            ds.unionByRank(u,v);
        }

        unordered_map<int,set<int>> mp;
        for(int i=1;i<=c;i++){
            int pi=ds.findUPar(i);

            mp[pi].insert(i);
        }


        vector<int> res;
        // O(Q*log(c))
        for(auto it:queries){
            int type=it[0];
            int node=it[1];
            int pnode=ds.findUPar(node);

            if(type==1){
                // maintenance

                if(mp[pnode].empty()){
                    res.push_back(-1);
                }
                else if(mp[pnode].find(node)!=mp[pnode].end()){
                    res.push_back(node);
                }
                else{
                    auto smll=*mp[pnode].begin();
                    res.push_back(smll);
                }
            }
            else{
                // offline
                mp[pnode].erase(node);
            }
        }

        return res;
    }
};
