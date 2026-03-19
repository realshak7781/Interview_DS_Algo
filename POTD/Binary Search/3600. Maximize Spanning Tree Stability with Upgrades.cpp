// Using Spanning tree kruskal logic + Binary Search
// Time : O(E) + O(log(ans)*[O(E) + O(n) + O(n)])
// space : O(n)
class DisjointSet {
private:
    vector<int> rank;
    vector<int> parent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int getComponentCount(int n) {
        unordered_set<int> componentCnt;

        for (int i = 0; i < n; i++) {
            int pu = findUParent(i);
            componentCnt.insert(pu);
        }

        return componentCnt.size();
    }
};

class Solution {
private:
    bool check(int mid,vector<vector<int>>& edges, int k, int n) {

        // adding edges with must==0 , using upgrades if necessary
        // only adding values which are >=minVal
        // if they are less than <minVal use upgrade , if using upgrade makes
        // them >=minVal then add them else leave me alone

        DisjointSet ds(n);
        vector<pair<int,int>> upgradesNeeded;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            int must=it[3];

            int pu=ds.findUParent(u);
            int pv=ds.findUParent(v);

            if(must==1){
                if(wt>=mid){
                    if(pu==pv) continue;
                    ds.unionByRank(u,v);
                }else{
                    return false;
                }
            }
            else{
                // must=0 , upgrade kr skte ho
                if(pu==pv) continue;

                if(wt>=mid){
                    ds.unionByRank(u,v);
                }
                else{
                    if(2*wt>=mid)upgradesNeeded.push_back({u,v});
                }
            }
        }



        // delayed upgardes logic
        for(auto &it:upgradesNeeded){
            int u=it.first;
            int v=it.second;

            int pu=ds.findUParent(u);
            int pv=ds.findUParent(v);

            if(pu==pv) continue;

            if(k>0){
                ds.unionByRank(u,v);
                k--;
            }
            else{
                return false;
            }
        }
        int totalComponents=ds.getComponentCount(n);

        return totalComponents==1;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DisjointSet ds(n);
        for (auto& it : edges) {
            int must = it[3];
            if (must == 1) {
                int pu=ds.findUParent(it[0]);
                int pv=ds.findUParent(it[1]);

                if(pu==pv) return -1;
                // a simple check to detect cycles
                ds.unionByRank(it[0],it[1]);
            }
        }

        int ans = -1;
        int low = 1;
        int high =2*1e5;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, edges, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
