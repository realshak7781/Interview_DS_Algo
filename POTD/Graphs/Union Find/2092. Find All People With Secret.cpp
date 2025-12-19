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
