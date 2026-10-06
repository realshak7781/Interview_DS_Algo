# time : O(n*n*logn)
# space : o(n*n)

class Solution:
    def check(self,safeScore,m,n,dist,dirs):
        if dist[0][0]<safeScore or dist[m-1][n-1]<safeScore:
            return False
        
        q=deque()
        q.append((0,0))

        vis=set()

        vis.add((0,0))

        while q:
            i,j=q.popleft()

            if i==m-1 and j==n-1:
                return True
            
            for dr,dc in dirs:
                ni=i+dr
                nj=j+dc

                if ni>=0 and ni<m and nj>=0 and nj<n and ((ni,nj) not in vis) and dist[ni][nj]>=safeScore:
                    q.append((ni,nj))
                    vis.add((ni,nj))
        
        return False

                    

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])

        if grid[0][0]==1 or grid[m-1][n-1]==1:
            return 0
        
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        q=deque()
        dist=[[float('inf')]*n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    q.append((i,j))
                    dist[i][j]=0
        
        # run bfs to update dist
        while q:
            size=len(q)

            for _ in range(size):
                i, j = q.popleft()

                for dr,dc in dirs:
                    ni=i+dr
                    nj=j+dc

                    if ni>=0 and ni<m and nj>=0 and nj<n:
                        newDist=dist[i][j]+1
                        if newDist<dist[ni][nj]:
                            dist[ni][nj]=newDist
                            q.append((ni,nj))
        

        low=0
        high=2*n
        res=0
        while low<=high:
            mid=low+(high-low)//2

            if self.check(mid,m,n,dist,dirs):
                res=mid
                low=mid+1
            else:
                high=mid-1
        
        return res

