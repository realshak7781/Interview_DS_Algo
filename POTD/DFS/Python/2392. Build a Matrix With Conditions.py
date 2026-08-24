# atime : O(R + C + k + k²)
# space : o(k*k)


class Solution:

    def dfs(self,node,adj,state,order):
        state[node]=1

        for neigh in adj[node]:
            if state[neigh]==1:
                return False
            
            if state[neigh]==2: continue

            if not self.dfs(neigh,adj,state,order):
                return False
        
        state[node]=2
        order.append(node)
        return True


    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:

        rowAdj=defaultdict(list)
        colAdj=defaultdict(list)

        for cnd in rowConditions:
            u=cnd[0]
            v=cnd[1]
            rowAdj[u].append(v)
        
        for cnd in colConditions:
            u=cnd[0]
            v=cnd[1]
            colAdj[u].append(v)
        
        state=[0]*(k+1)
        rowOrder=[]

        for i in range(1,k+1):
            if state[i]==0:
                if not self.dfs(i,rowAdj,state,rowOrder):
                    return {}
        
        rowOrder.reverse()

        state=[0]*(k+1)
        colOrder=[]
        for i in range(1,k+1):
            if state[i]==0:
                if not self.dfs(i,colAdj,state,colOrder):
                    return {}
        
        colOrder.reverse()

        rowPos=[0]*(k+1)
        colPos=[0]*(k+1)

        for i in range(0,k):
            rowPos[rowOrder[i]]=i
            colPos[colOrder[i]]=i
        

        res=[[0 for _ in range(k)] for _ in range(k)]

        for val in range(1,k+1):
            res[rowPos[val]][colPos[val]]=val
        
        return res

        
