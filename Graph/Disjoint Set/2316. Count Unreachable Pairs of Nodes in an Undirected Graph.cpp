
  //    O(E·α(n) + n·α(n)) = O((E + n)·α(n))
using ll=long long;
class disjointSet{
    private:
    vector<int> parent;
    vector<int> rank;
    int totalNodes;

    public:
    disjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        totalNodes=n;
    }


    int findUPar(int node){
        if(node==parent[node])return node;
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
            parent[pv]=pu;
            rank[pu]+=1;
        }
    }

    ll getPairCounts(){
        unordered_map<int,ll> mp;
        // stores ultimate parent and its child Count;

        for(int i=0;i<totalNodes;i++){
            int pi=findUPar(i);
            mp[pi]++;
        }
        ll totalPairs=(1LL*totalNodes*(totalNodes-1))/2;

        for(auto &[root,size]:mp){
            totalPairs-=(1LL*(size)*(size-1))/2;
        }

        return totalPairs;
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        disjointSet ds(n);

        for(auto &it:edges){
            int pu=ds.findUPar(it[0]);
            int pv=ds.findUPar(it[1]);
            if(pu==pv) continue;
            ds.unionByRank(pu,pv);
            //   O(E·α(n) 
        }

        ll pairCounts=ds.getPairCounts();
        // O(n·α(n))

        return pairCounts;
    }
};
