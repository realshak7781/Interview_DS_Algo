
# SIUIING BRUTE FORCE APPROACH
class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m=len(boxGrid)
        n=len(boxGrid[0])

        res=[['.' for _ in range(n)] for _ in range(m)]

        for i in range(m):
            stones=0
            for j in range(n):
                if boxGrid[i][j]=='#':
                    stones+=1
                
                if(boxGrid[i][j]=='*'):
                    res[i][j]='*'
                    col=j-1

                    while stones>0 and col>=0:
                        res[i][col]='#'
                        col-=1
                        stones-=1
            
            col=n-1
            while stones>0 and col>=0:
                res[i][col]='#'
                col-=1
                stones-=1
            
        
        rotatedRes=[['.' for _ in range(m)] for _ in range(n)]

        for i in range(m):
            for j in range(n):
                rotatedRes[j][m-i-1]=res[i][j]
        
        return rotatedRes
