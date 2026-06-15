
class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        perimeter=4*side
        flattened=[]

        for i in range(len(points)):
            x=points[i][0]
            y=points[i][1]

            dist=-1
            if y==0:
                dist=x
            elif x==side:
                dist=side+y
            elif y==side:
                dist=3*side-x
            elif x==0:
                dist=4*side-y
            
            flattened.append(dist)
            flattened.append(dist+perimeter)
        
        flattened.sort()

        low=0
        high=2*side

        res=0
        while low<=high:
            mid=low+(high-low)//2

            if self.check(mid,flattened,k,perimeter):
                res=mid
                low=mid+1
            else:
                high=mid-1
        
        return res
    
    def check(self,mid:int,flattened:List[List[int]],k:int,perimeter:int):
        n=len(flattened)

        for i in range(n):
            startPos=flattened[i]
            cnt=1

            lastPos=startPos

            while cnt<k:
                target=lastPos+mid
                idx = bisect_left(flattened, target, i + 1)

                if idx>=n:
                    break
                cnt+=1
                lastPos=flattened[idx]
            
            if cnt==k and (startPos+perimeter-lastPos)>=mid:
                return True
        
        return False
