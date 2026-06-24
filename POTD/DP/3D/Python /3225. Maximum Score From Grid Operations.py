class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n=len(grid)
        colPrefSum=[[0]*(n+1) for _ in range(n+1)]

        for col in range(1,n+1):
            for row in range(1,n+1):
                colPrefSum[row][col]=colPrefSum[row-1][col]+grid[row-1][col-1]
        
        self.memo = [[[-1] * 2 for _ in range(102)] for _ in range(102)]
        return self.solve(-1,0,False,grid,colPrefSum,n)

    
    def solve(self,prev_h:int,col:int,prev_taken:bool,grid:List[List[int]],colPrefSum:List[List[int]],n:int):
        if col>=n:
            return 0

        if self.memo[prev_h + 1][col][prev_taken]!=-1:
            return self.memo[prev_h + 1][col][prev_taken]
        result=0

        for height in range(-1,n):
            cur_h=height
            prevScore=0
            curScore=0

            if prev_h>cur_h:
                curScore=colPrefSum[prev_h+1][col+1]-colPrefSum[cur_h+1][col+1]
            
            if not prev_taken and cur_h>prev_h:
                prevScore=colPrefSum[cur_h+1][col]-colPrefSum[prev_h+1][col]
            
            curTaken=curScore+prevScore + self.solve(cur_h,col+1,True,grid,colPrefSum,n)
            curNotTaken=prevScore + self.solve(cur_h,col+1,False,grid,colPrefSum,n)

            result = max(result, curTaken, curNotTaken)
        
        self.memo[prev_h + 1][col][prev_taken]=result
        return self.memo[prev_h + 1][col][prev_taken]

