# TIME : O(M*N)
# SPACE : O(M*N)


class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])

        dx = [0, 0, 0, 1, -1]
        dy = [0, 1, -1, 0, 0]

        dq=deque()
        dist=[[10**9 for _ in range(n)] for _ in range(m)]

        dq.append((0,0))
        # push back
        dist[0][0]=0

        while dq:
            i,j=dq[0]
            dq.popleft()

            if i==m-1 and j==n-1:
                return dist[i][j]
            
            for k in range(1,5):
                nx=i+dx[k]
                ny=j+dy[k]

                if nx<0 or nx>=m or ny<0 or ny>=n:
                    continue
                
                cost= 0 if grid[i][j]==k else 1

                if dist[i][j]+cost<dist[nx][ny]:
                    dist[nx][ny]=dist[i][j]+cost

                    if cost==0:
                        dq.appendleft((nx,ny))
                    else:
                        dq.append((nx,ny))
        

        return dist[m-1][n-1]
