# optimized approach:
class Solution:

    def solve(self,rods):

        @cache
        def getHeight(idx,diff):
            if idx>=len(rods):
                return 0 if diff==0 else float('-inf')
            
            rod_len=rods[idx]

            skip=getHeight(idx+1,diff)
            putFirstSub=rod_len+ getHeight(idx+1,diff+rod_len)
            putSecondSub=getHeight(idx+1,diff-rod_len)

            res=max(skip,putFirstSub,putSecondSub)

            return res
        
        res_height=getHeight(0,0)

        return res_height

    def tallestBillboard(self, rods: List[int]) -> int:
        
        return self.solve(rods)


# MLE : due to idx*firstSUm*seconndSum size cache
# imporve using maths
class Solution:

    def solve(self,rods):

        @cache
        def getHeight(idx,firstSum,secondSum):
            if idx>=len(rods):
                if firstSum==secondSum:
                    return firstSum
                return 0
            
            res=0
            res=max(res,getHeight(idx+1,firstSum+rods[idx],secondSum))
            res=max(res,getHeight(idx+1,firstSum,secondSum+rods[idx]))
            res=max(res,getHeight(idx+1,firstSum,secondSum))

            return res
        
        res_height=getHeight(0,0,0)

        return res_height

    def tallestBillboard(self, rods: List[int]) -> int:
        
        return self.solve(rods)
