class Solution:

    def updateGrid(self,sr:int,er:int,sc:int,ec:int,grid: List[List[int]], k: int):
        temp=[]

        # populate top row
        for j in range(sc,ec+1):
            temp.append(grid[sr][j])

        # popilaye last col
        for i in range(sr+1,er+1):
            temp.append(grid[i][ec])
        
        # populate last row
        for j in range(ec-1,sc-1,-1):
            temp.append(grid[er][j])
        
        # populate start row
        for i in range(er-1,sr,-1):
            temp.append(grid[i][sc])
        
        n=len(temp)
        k=k%n
        
        # populate back

        # populate top row
        rotIdx=0
        for j in range(sc,ec+1):
            putIdx=(rotIdx+k)%n
            grid[sr][j]=temp[putIdx]
            rotIdx += 1

        # popilaye last col
        for i in range(sr+1,er+1):
            putIdx=(rotIdx+k)%n
            grid[i][ec]=temp[putIdx]
            rotIdx+=1
        
        # populate last row
        for j in range(ec-1,sc-1,-1):
            putIdx=(rotIdx+k)%n
            grid[er][j]=temp[putIdx]
            rotIdx+=1
        
        # populate start row
        for i in range(er-1,sr,-1):
            putIdx=(rotIdx+k)%n
            grid[i][sc]=temp[putIdx]
            rotIdx+=1

    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m=len(grid)
        n=len(grid[0])

        sr,er,sc,ec=0,m-1,0,n-1

        while sr<er and sc<ec:
            self.updateGrid(sr,er,sc,ec,grid,k)
            sr+=1
            er-=1
            sc+=1
            ec-=1
        
        return grid
