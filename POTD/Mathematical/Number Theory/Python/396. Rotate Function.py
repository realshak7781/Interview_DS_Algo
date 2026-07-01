class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n=len(nums)
        f0=0
        sum_of_nums=0

        for idx,val in enumerate(nums):
            f0=f0+idx*val
            sum_of_nums=sum_of_nums+val
        

        prev_f=f0
        maxRes=f0

        for k in range(1,n):
            fk=prev_f+sum_of_nums - n*nums[n-k]
            maxRes=max(maxRes,fk)

            prev_f=fk
        

        return maxRes
