# TIME : O(Q*LOGN)
# SPACE : O(4*N)
class Solution:
    def getLeft(self, target: int, index: List[int]) -> int:
        res = -1
        low = 0
        high = len(index) - 1

        while low <= high:
            mid = low + (high - low) // 2
            if index[mid] < target:
                low = mid + 1
            else:
                res = mid
                high = mid - 1
        
        return res

    def getRight(self, target: int, index: List[int]) -> int:
        res = -1
        low = 0
        high = len(index) - 1

        while low <= high:
            mid = low + (high - low) // 2
            if index[mid] <= target:
                res = mid
                low = mid + 1 
            else:
                high = mid - 1
        
        return res
    
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        res = []
        MOD = 10**9 + 7
        
        prefSum = [0] * n
        prefSum[0] = int(s[0])
        for i in range(1, n):
            prefSum[i] = prefSum[i - 1] + int(s[i])
        
        pow10 = [1] * (n + 1)
        for i in range(1, len(pow10)):
            pow10[i] = (pow10[i - 1] * 10) % MOD

        index = []
        x = 0
        P = []
        for i in range(n):
            val = int(s[i])
            if val == 0:
                continue
            index.append(i)
            x = (x * 10 + val) % MOD
            P.append(x)
        
        for l, r in queries:
            digit_sum = prefSum[r] - (prefSum[l - 1] if l > 0 else 0)

            leftIdx = self.getLeft(l, index)
            rightIdx = self.getRight(r, index)

            if leftIdx == -1 or rightIdx == -1 or leftIdx > rightIdx:
                res.append(0)
                continue
            
            p_left = P[leftIdx - 1] if leftIdx > 0 else 0
            p_right = P[rightIdx]
            cnt = rightIdx - leftIdx + 1
            
            formed_num = (p_right - pow10[cnt] * p_left) % MOD
            ans = (formed_num * digit_sum) % MOD
            res.append(ans)
        
        return res
