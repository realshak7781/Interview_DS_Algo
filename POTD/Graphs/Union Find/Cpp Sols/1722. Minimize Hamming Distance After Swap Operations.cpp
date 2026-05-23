// TIME : O((N+M)*ALPHA(N))
// SPACE : O(N)

class disjointSet{
    vector<int> parent;
    vector<int> rank;

    public:
    disjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
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
        else if(rank[pv]<rank[pu]){
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int size=source.size();
        disjointSet ds(size);

        for(auto &swap:allowedSwaps){
            ds.unionByRank(swap[0],swap[1]);
        }

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<size;i++){
            mp[ds.findUPar(i)].push_back(i);
        }

        int minHamDist=0;

        for(auto &it:mp){
            auto &vec=it.second;

            unordered_map<int,int> reducer;

            for(auto &idx:vec){
                // first populate from source
                reducer[source[idx]]++;
            }

            // then reduce from target
            for(auto&idx:vec){
                if(reducer[target[idx]]>0){
                    reducer[target[idx]]--;
                }
                else{
                    minHamDist++;
                }
            }
        }

        return minHamDist;
    }
};
