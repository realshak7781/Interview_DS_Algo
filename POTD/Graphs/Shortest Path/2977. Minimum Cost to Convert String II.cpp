// TIME : O(m) + o(M*LOG(M)) + O(S*UNIQUE_SUB_LEN(l*l*(v+e)logv)))
//  l= no of source  and target substrings

// SPACE : O(m)+ O(LEN)  + o(l*l*(v+e) + O(nodes) + o (nodes))

// USING  DP+DIJKSTRAS + DIJKSTRAS MEMOIZATION + DP MEMOIZATION
using ll=long long;
using p=pair<string,ll>;
using dijkP=pair<ll,string>;
const ll inf=1e10;
class Solution {
private:
unordered_map<string,vector<p>> adjList;
set<int> possibleSubLen;
vector<ll> dp;

unordered_map<string,unordered_map<string,ll>> dijkMemo;
ll dijkstras(string &source,string &target){

    if(dijkMemo[source].count(target)) return dijkMemo[source][target];

    priority_queue<dijkP,vector<dijkP>,greater<dijkP>> pq;
    unordered_map<string,ll> dist;
    unordered_set<string> seen;

    pq.push({0,source});
    dist[source]=0;

    while(!pq.empty()){
        string node=pq.top().second;
        pq.pop();

        if(seen.count(node)) continue;

        seen.insert(node);


        for(auto &neigh:adjList[node]){
            string v=neigh.first;
            int wt=neigh.second;

            if(!dist.count(v) || (dist[node]+wt) < dist[v]){
                dist[v]=dist[node]+wt;
                pq.push({dist[v],v});
            }
        }
    }

    return dijkMemo[source][target]=dist.count(target) ? dist[target] : inf;
}
ll solve(int idx,string source, string target, vector<string>& original, vector<string>& changed){
    if(idx>=source.length()){
        return 0;
    }

    if(dp[idx]!=-1) return dp[idx];
    ll minCost=inf;
    if(source[idx]==target[idx]){
        minCost=min(minCost,0+solve(idx+1,source,target,original,changed));
    }

    // try alll possible substrings
    for(auto &len:possibleSubLen){
        if((idx+len)>source.length()) break;

        string sourceSub=source.substr(idx,len);
        string targetSub=target.substr(idx,len);

        if(!adjList.count(sourceSub)) continue;

        ll transformCost=dijkstras(sourceSub,targetSub);

        if(transformCost==inf) continue;

        minCost=min(minCost,transformCost+solve(idx+len,source,target,original,changed));
    }

    return dp[idx]=minCost;
}
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        
        // building the adjacency list using the original and changed
        for(int i=0;i<original.size();i++){
          // o(M)
            string u=original[i];
            string v=changed[i];
            int wt=cost[i];

            adjList[u].push_back({v,1LL*wt});
        }

        // find all the possible substring lengths that can be made;
        // using the original sub len
        
        for(auto &s:original){
            possibleSubLen.insert(s.length());
        }

        dp.resize(source.length()+1,-1);
        ll res=solve(0,source,target,original,changed);
        return res>=inf ? -1 : res;
    }
};
