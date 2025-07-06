class disjointSet{
    private:
    vector<int> parent;
    vector<int> rank;

    public:
    disjointSet(int c){
        rank.resize(c+1,0);
        parent.resize(c+1,0);
        for(int i=1;i<=c;i++){
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
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};


class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        disjointSet ds(c);
        for(auto &it:connections){
            int u=it[0],v=it[1];
            ds.unionByRank(u,v);
        }

        unordered_set<int> offlineNodes;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>> >mp;

        for(int i=1;i<=c;i++){
            mp[ds.findUPar(i)].push(i);
        }


        vector<int> res;

        for(auto &it:queries){
            int type=it[0];
            int x=it[1];

            if(type==2){
                offlineNodes.insert(x);
            }
            else{

                if(!offlineNodes.count(x)){
                    res.push_back(x);
                    continue;
                }
                auto &pq=mp[ds.findUPar(x)];
                while(!pq.empty() && offlineNodes.count(pq.top())){
                    pq.pop();
                }

                if(!pq.empty()){
                    res.push_back(pq.top());
                }
                else{
                    res.push_back(-1);
                }
            }
        }

        return res;
    }
    
};
