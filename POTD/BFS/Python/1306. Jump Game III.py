# TIME : O(N)
# SPACE : O(N)

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n=len(arr)
        q=deque()
        s=set()

        q.append(start)
        s.add(start)

        while q:
            idx=q[0]
            q.popleft()

            if arr[idx]==0:
                return True
            
            rightFar=idx+arr[idx]
            leftFar=idx-arr[idx]

            if rightFar<n and rightFar not in s:
                s.add(rightFar)
                q.append(rightFar)
            
            if leftFar>=0 and leftFar not in s:
                s.add(leftFar)
                q.append(leftFar)
        
        return False

