class disjointSet{
    private:
    vector<int> parent,rank;
    int totalNodes;
    public:

    disjointSet(int size){
        rank.resize(size,0);
        parent.resize(size);

        for(int i=0;i<size;i++){
            parent[i]=i;
        }
        totalNodes=size;
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
            parent[pv]=pu;
            rank[pu]++;
        }
    }


    int getCompCount(){
        unordered_set<int> st;

        for(int i=0;i<totalNodes;i++){
            int pi=findUPar(i);
            st.insert(pi);
        }

        return st.size();
    }
};
class Solution {
private:
int intersect(vector<int>&a,vector<int>&b){
    vector<bool> distinct(101,false);
    for(int val:a){
        distinct[val]=true;
    }
    unordered_set<int> st(begin(b),end(b));

    int count=0;
    for(int val:st){
        if(distinct[val]){
            count++;
        }
    }
    return count;
}
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int totalNodes=properties.size();

        disjointSet ds(totalNodes);
     
        for(int i=0;i<totalNodes;i++){
            for(int j=i+1;j<totalNodes;j++){
                if(intersect(properties[i],properties[j])>=k){
                    int pi=ds.findUPar(i);
                    int pj=ds.findUPar(j);

                    if(pi==pj) continue;

                    ds.unionByRank(pi,pj);
                }
            }
        }


        return ds.getCompCount();
    }
};
