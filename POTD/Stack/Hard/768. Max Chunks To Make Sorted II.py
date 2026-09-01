# APPROACH : USING SUFFIX MIN AND PREFIX MAX
# TIME : O(N)
# SPACE : O(N)
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n=len(arr)
        suffixMin=[0]*n

        suffixMin[-1]=arr[-1]

        for i in range(n-2,-1,-1):
            suffixMin[i]=min(suffixMin[i+1],arr[i])
        

        chunks=0
        prefixMax=float('-inf')

        for i in range(n-1):
            prefixMax=max(prefixMax,arr[i])

            if prefixMax<=suffixMin[i+1]:
                chunks+=1
        
        return chunks+1


# TIME : O(N^3)
# SPACE : O(N*N)
# APPROACH 1: USING CACHING RECURSION
class Solution:

    def maxChunksToSorted(self, arr: List[int]) -> int:

        n = len(arr)

        @cache
        def solve(idx, prevMaxIdx):
            if idx >= n:
                return 0

            curMin = float("inf")
            curMaxIdx = -1
            curMaxVal = float("-inf")
            prevMaxVal = float("-inf") if prevMaxIdx == -1 else arr[prevMaxIdx]

            ans = float("-inf")

            for j in range(idx, n):
                curMin = min(curMin, arr[j])
                if arr[j] > curMaxVal:
                    curMaxVal = arr[j]
                    curMaxIdx = j

                # Chunking condition for the recursive step
                if curMin >= prevMaxVal:
                    res = solve(j + 1,curMaxIdx)
                    if res!=float("-inf"):
                        ans = max(ans, 1 + res)

            return ans 

        res=solve(0, -1)

        if res==float('-inf'):
            return 0
        
        return res
