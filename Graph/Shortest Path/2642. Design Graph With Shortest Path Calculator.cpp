using p=pair<int,int>;
const int inf=INT_MAX;
class Graph {
private:
unordered_map<int,vector<p>> adjList;
int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            adjList[u].push_back(make_pair(v,w));
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];

        adjList[u].push_back(make_pair(v,w));
    }

    void dijkstras(int src,vector<int> &dist){
        dist[src]=0;
        priority_queue<p,vector<p>,greater<p>>minHeap;

        minHeap.push({0,src});

        while(!minHeap.empty()){
            auto [curDist,u]=minHeap.top();
            minHeap.pop();

            if(dist[u]==inf || curDist>dist[u]) continue;

            for(auto [v,wt]:adjList[u]){
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                    minHeap.push({dist[v],v});
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n,inf);

        dijkstras(node1,dist);

        int d=dist[node2];

        return d==inf?-1:d;
    }
};
