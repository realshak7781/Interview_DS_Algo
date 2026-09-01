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
