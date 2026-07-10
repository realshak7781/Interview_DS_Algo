//APPROACH 2 : USING BOTTOM UP APPROACH
// TIME :O (N*n)
// SPACE : O(N*N)
class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n=len(nums)
        jumpMp=defaultdict(list)

        for i,ni in enumerate(nums):
            for j in range(i+1,n):
                mini=ni-target
                maxi=ni+target

                if nums[j]>=mini and nums[j]<=maxi:
                    jumpMp[i].append(j)

        def solve():
            dp=[0]*n

            for idx in range(n-2,-1,-1):
                maxSteps=float('-inf')

                for jIdx in jumpMp[idx]:
                    step=dp[jIdx]

                    if step!=float('-inf'):
                        maxSteps=max(maxSteps,1+step)
                
                dp[idx]=maxSteps
            
            return dp[0]

        res=solve()

        return -1 if res==float('-inf') else res

// Approach 1 : Using top down recursive approach
// time : O(n*n)
// space : O(n*n) + O(n)


class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n=len(nums)
        jumpMp=defaultdict(list)

        for i,ni in enumerate(nums):
            for j in range(i+1,n):
                mini=ni-target
                maxi=ni+target

                if nums[j]>=mini and nums[j]<=maxi:
                    jumpMp[i].append(j)

        @cache
        def solve(idx):
            if idx==n-1:
                return 0
            
            maxSteps=float('-inf')

            for jIdx in jumpMp[idx]:
                step=solve(jIdx)

                if step!=float('-inf'):
                    maxSteps=max(maxSteps,1+step)
            
            return maxSteps
        

        res=solve(0)

        return -1 if res==float('-inf') else res
