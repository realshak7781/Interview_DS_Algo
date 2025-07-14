class disjointSet{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    disjointSet(int n){
        parent.resize(n);
        rank.resize(n,1);

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
            parent[pv]=pu;
            rank[pu]+=1;
        }
    }
};


class Solution {
private:
int getComponentCount(int mid,vector<vector<int>>& edges,int n){
    disjointSet ds(n);

    for(auto &it:edges){
        if(it[2]<=mid){
            ds.unionByRank(it[0],it[1]);
        }
    }
    
    unordered_set<int> compCount;
    for(int i=0;i<n;i++){
        compCount.insert(ds.findUPar(i));
    }

    return compCount.size();
}
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int maxWeight=INT_MIN;
        for(auto &it:edges){
            maxWeight=max(maxWeight,it[2]);
        }
        int left=0,right=maxWeight;
        int cost=0;
        while(left<=right){
            int mid=left+(right-left)/2;

            if(getComponentCount(mid,edges,n)<=k){
                cost=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }

        return cost;
    }
};
