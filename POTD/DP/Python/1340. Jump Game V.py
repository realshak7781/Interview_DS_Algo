

# TIME : O(N*D)
# SPACE : O(N) + O(N)
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)

        @cache
        def solve(i:int):
            jumpCnt = 1
            minRange = i - d
            maxRange = i + d

            # jumping right: i ----> j
            for j in range(i + 1, min(n, maxRange + 1)):
                if arr[j] >= arr[i]:
                    break
                else:
                    jumpCnt = max(jumpCnt, 1 + solve(j))
            
            # jumping left: i ----> j
            for j in range(i - 1, max(-1, minRange - 1), -1):
                if arr[j] >= arr[i]:
                    break
                else:
                    jumpCnt = max(jumpCnt, 1 + solve(j))

            return jumpCnt

        res = max(solve(i) for i in range(n))
        return res
