class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // build the adjaceny list:
        unordered_map<int,vector<int>> adjList;
        unordered_map<int,int> inDegree,outDegree;
        for(auto &it:pairs){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            // u--->v
            inDegree[v]++;
            outDegree[u]++;
        }


        // find the startNode of Euler path : OutDegree[n]-inDegree[n]=1;
        int startNode=pairs[0][0];
        for(auto &it:outDegree){
            int node=it.first;
            int deg=it.second;

            if((deg-inDegree[node])==1){
                startNode=node;
                break;
            }
        }

        vector<int> eulerPath;
        stack<int> st;
        st.push(startNode);
        
        while(!st.empty()){
            int cur=st.top();

            if(!adjList[cur].empty()){
                st.push(adjList[cur].back());
                adjList[cur].pop_back();
            }
            else{
                eulerPath.push_back(cur);
                st.pop();
            }
        }

        // build your euler path
        reverse(eulerPath.begin(),eulerPath.end());
        vector<vector<int>> res;

        for(int i=0;i<eulerPath.size()-1;i++){
            int u=eulerPath[i];
            int v=eulerPath[i+1];

            res.push_back({u,v});
        }


        return res;

    }
};
