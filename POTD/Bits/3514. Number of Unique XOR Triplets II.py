# Learnins :
# USING AN O(N*N) APPROACH : 
# THE SET WILL ALWAYS CONTAIN LESS THAN 2* MAX(NUMS)  ELEMENTS , SO THAT WORKS FOR THE AGREED TIME COMPLEZITY
# SINCE DOESNT INTRODUCE EXTRA BIT, THE CONSTRAINS WORK FOR THE N^2 APPROACH

class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n=len(nums)
        allPossibleXorVal=set()

        for i in range(n):
            for j in range(i,n):
                xorVal=nums[i]^nums[j]
                allPossibleXorVal.add(xorVal)
        

        seen=set()
        uniqueXorCnt=0

        for xorVal in allPossibleXorVal:
            for k in range(n):
                finalXorVal=xorVal ^ nums[k]

                if finalXorVal not in seen:
                    seen.add(finalXorVal)
                    uniqueXorCnt+=1
        
        return uniqueXorCnt
