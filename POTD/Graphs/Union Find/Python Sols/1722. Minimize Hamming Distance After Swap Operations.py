
class disjointSet:
    def __init__(self,n:int):
         self.parent=list(range(n))
         self.rank=[0] * n
    
    def findUPar(self,node:int)->int:
        if node==self.parent[node]:
            return node
        
        self.parent[node]=self.findUPar(self.parent[node])
        return self.parent[node]
    
    
    def unionByRank(self,u:int,v:int):
        pu=self.findUPar(u)
        pv=self.findUPar(v)

        if pu==pv:
            return
        
        if self.rank[pu] < self.rank[pv]:
            self.parent[pu]=pv
        elif self.rank[pv] < self.rank[pu]:
            self.parent[pv]=pu
        else:
            self.parent[pu]=pv
            self.rank[pv]+=1
    

        

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        size=len(source)

        ds = disjointSet(size)

        for u,v in allowedSwaps:
            ds.unionByRank(u,v)
        
        mp= collections.defaultdict(list)
        for i in range(size):
            mp[ds.findUPar(i)].append(i)
        
        minHamDist=0

        for p,vec in mp.items():
            reducer=collections.defaultdict(int)

            for idx in vec:
                reducer[source[idx]]+=1
            
            # now reduce

            for idx in vec:
                if reducer[target[idx]]>0:
                    reducer[target[idx]]-=1
                else:
                    minHamDist+=1
            
        
        return minHamDist
