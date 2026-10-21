# TIME : O(Q*LOG(M))
# SPACE : O(M+Q)
# LEARNINGS :
         # BEING ABLE TO FIND THE GCD OF AN ARRAY OF NUMS , PRETTY USEFUL IN LOT OF QUESTIONS
          # USING BINARY SEARCH AND CUM SUM FOR FINDING THE RIGHT IDX

class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        max_fac=max(nums)
        
        factorFreq=[0]*(max_fac+1)
        for elem in nums:
            i=1
            while i*i<=elem:
                if elem%i==0:
                    factorFreq[i]+=1

                    if i!=elem//i:
                        factorFreq[elem//i]+=1
                i+=1
        
        # now cnt pairs of how many pairs exists for a factor
        pairCntMp=[0]*(max_fac+1)
        for fac in range(max_fac,0,-1):
            freq=factorFreq[fac]
            if freq==0 or freq==1:
                continue
            
            pairCnt=(freq*(freq-1))//2
            pairCntMp[fac]=pairCnt

            # adjust for duplicates pairs
            for mul in range(2*fac,max_fac+1,fac):
                pairCntMp[fac]-=pairCntMp[mul]
        
        # take cumulative sum
        for i in range(1,max_fac+1):
            pairCntMp[i]+=pairCntMp[i-1]
        

        # do a binary search for queries
        resultant=[]

        for q in queries:
            target=q+1

            low=0
            high=max_fac
            res=-1
            while low<=high:
                mid=low+(high-low)//2

                if pairCntMp[mid]>=target:
                    res=mid
                    high=mid-1
                else:
                    low=mid+1
            
            resultant.append(res)
        
        return resultant


