# TIME : O(M*N)
# SPACE : O(M*N)

class Solution:
    def getMaxScore(self,i,j,m,n,board,dirs,MOD,memo):
        if i==m-1 and j==n-1:
            return 0
        
        if memo[i][j] is not None:
            return memo[i][j]

        maxScore=float('-inf')
        for dr,dc in dirs:
            ni=i+dr
            nj=j+dc

            if ni>=0 and ni<m and nj>=0 and nj<n:
                if board[ni][nj]=='X':
                    continue
                
                val = int(board[ni][nj]) if board[ni][nj].isdigit() else 0
                nextScore=self.getMaxScore(ni,nj,m,n,board,dirs,MOD,memo)%MOD
                if nextScore!=float('-inf'):
                    maxScore=max(maxScore,val+nextScore)
        
        memo[i][j]=maxScore
        return memo[i][j]

    def findWays(self,i,j,m,n,board,dirs,MOD,memo2,memo1):
        if i==m-1 and j==n-1:
            return 1 
        
        if memo2[i][j] is not None:
            return memo2[i][j]
        ways=0
        for dr,dc in dirs:
            ni=i+dr
            nj=j+dc

            if ni>=0 and ni<m and nj>=0 and nj<n:
                if board[ni][nj]=='X':
                    continue
                val=(int(board[ni][nj]) if board[ni][nj].isdigit() else 0)

                if memo1[ni][nj]!=float('-inf')  and (val+memo1[ni][nj])==memo1[i][j]:
                    ways=(ways+self.findWays(ni,nj,m,n,board,dirs,MOD,memo2,memo1))%MOD
     
        memo2[i][j]=ways
        return ways
    def pathsWithMaxScore(self, board: list[str]) -> list[int]:
        m=len(board)
        n=len(board[0])
        dirs = [(0, 1), (1, 0), (1, 1)]
        MOD=10**9+7

        memo1 = [[None] * n for _ in range(m)]
        maxScore=self.getMaxScore(0,0,m,n,board,dirs,MOD,memo1)

        if maxScore==float('-inf'):
            return [0,0]
        
        memo2 = [[None] * n for _ in range(m)]
        memo1[m-1][n-1]=0
        ways=self.findWays(0,0,m,n,board,dirs,MOD,memo2,memo1)


        return [maxScore%MOD,ways]
