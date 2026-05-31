
class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        n=len(nums)
        idxMp=defaultdict(list)
        pfMp=defaultdict(list)

        for i in range(n):
            idxMp[nums[i]].append(i)
        
        for val,vec in idxMp.items():
            pfMp[val]=[0] * len(vec)
            pfMp[val][0]=vec[0]

            for i in range(1,len(vec)):
                pfMp[val][i]=vec[i]+pfMp[val][i-1]
        
        res=[0]*n

        for i in range(n):
            val=nums[i]
            vec=idxMp[val]
            prefVec=pfMp[val]

            idx=self.binarySearch(0,len(vec)-1,vec,i)

            if idx==-1:
                continue
            
            leftElemCnt=idx-0
            rightElemCnt=len(vec)-idx-1

            leftAbsSum=leftElemCnt*i - (prefVec[idx-1] if idx>0 else 0)
            rightAbsSum=(prefVec[len(vec)-1]-prefVec[idx]) - rightElemCnt*i

            res[i]=leftAbsSum+rightAbsSum
        
        return res
    

    def binarySearch(self,left:int,right:int,vec:List[int],target:int)->int:

        while left<=right:
            mid=left+(right-left)//2

            if vec[mid]==target:
                return mid
            elif vec[mid]>target:
                right=mid-1
            else:
                left=mid+1
        
        return -1

