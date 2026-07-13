class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n=len(nums)
        diff=[0]*(2*limit+2)

        for i in range(0,n//2):
            sum=nums[i]+nums[n-i-1]
            low=min(nums[i],nums[n-i-1])+1
            high=max(nums[i],nums[n-i-1])+limit

            diff[2]+=2
            diff[2*limit+1]-=2

            diff[low]-=1
            diff[high+1]+=1

            diff[sum]-=1
            diff[sum+1]+=1
        

        for i in range(3,2*limit+2):
            diff[i]=diff[i-1]+diff[i]
        

        minMoves=float('inf')
        for i in range(2,2*limit+1):
            minMoves=min(minMoves,diff[i])
        
        return minMoves
