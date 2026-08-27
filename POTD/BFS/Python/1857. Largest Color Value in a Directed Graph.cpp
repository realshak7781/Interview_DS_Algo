// TIME : O(V+E)
// SPACE : O(V) + O(V+E)

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        totalNodes=len(colors)
        inDegree=[0]*(totalNodes)
        dp=[[0 for _ in range(26)] for _ in range(totalNodes)]

        adj=defaultdict(list)

        for edg in edges:
            u=edg[0]
            v=edg[1]
            adj[u].append(v)
            inDegree[v]+=1
        
        q=deque()
        for node,deg in enumerate(inDegree):
            if deg==0:
                q.append(node)

        nodesVisited=0
        while q:
            node=q[0]
            q.popleft()

            nodesVisited+=1
            cIdx = ord(colors[node]) - ord('a')
            dp[node][cIdx]+=1

            for neigh in adj[node]:

                for chIdx in range(26):
                    dp[neigh][chIdx]=max(dp[neigh][chIdx],dp[node][chIdx])
                inDegree[neigh]-=1
                if inDegree[neigh]==0:
                    q.append(neigh)

        

        if nodesVisited!=totalNodes:
            return -1
        
        maxLen=1

        for i in range(totalNodes):
            for j in range(26):
                maxLen=max(maxLen,dp[i][j])
        
        return maxLen
