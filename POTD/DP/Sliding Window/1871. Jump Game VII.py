# TIME : o(N)
# APACE : o(n)

class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n=len(s)
        canReach=[False]*n
        canReach[0]=True

        i,j=0,0
        zeroCnt=1
        windowSize=maxJump-minJump+1

        for v in range(minJump,n):
            if s[v]=='0' and zeroCnt>0:
                canReach[v]=True
            
            curWindowSize=j-i+1

            if curWindowSize<windowSize:
                j+=1

                if j<n and canReach[j]:
                    zeroCnt+=1
            else:
                if canReach[i]:
                    zeroCnt-=1
                i+=1
                j+=1

                if j<n and canReach[j]:
                    zeroCnt+=1
        

        return (s[n-1]=='0' and canReach[n-1])
