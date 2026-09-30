# OPTIMIZED A LOT AFTER A LOT OF BRAINSTORMING 
# FINALLY DECIDED TO USE SEGMENT TREE TO QUERY , ONE CAM USE FENWICK TREE
# THERE IS A O(N) APPROACH ALSP : BUT ITS NOT INTUITIVE
# SHOULD TRY THE SEG APPROACH: AS SEG TREE IS USEFUL IN LOT OF QUESTIONS

class Solution:
    def query(self,nodeIdx,ql,qr,l,r,seg):
        if ql>r or qr<l:
            return 0
        
        if l>=ql and r<=qr:
            return seg[nodeIdx]
        
        mid=l+(r-l)//2
        leftAns=self.query(2*nodeIdx+1,ql,qr,l,mid,seg)
        rightAns=self.query(2*nodeIdx+2,ql,qr,mid+1,r,seg)

        return leftAns + rightAns
    
    def update(self,nodeIdx,upVal,targetIdx,l,r,seg):
        if l==r:
            seg[nodeIdx]+=upVal
            return
        mid=l+(r-l)//2

        if targetIdx<=mid:
            self.update(2*nodeIdx+1,upVal,targetIdx,l,mid,seg)
        else:
            self.update(2*nodeIdx+2,upVal,targetIdx,mid+1,r,seg)
        
        seg[nodeIdx]=seg[2*nodeIdx+1] + seg[2*nodeIdx+2]
    

    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n=len(nums)
        offset=n
        maxSize=2*n+1
        seg=[0]*(4*maxSize)

        # insert 0 first with an offset : insert(0+offset)
        targetIdx=0+n
        self.update(0,1,targetIdx,0,2*n,seg)

        # convert the array to -1,+1
        for i in range(n):
            if nums[i]==target:
                nums[i]=1
            else:
                nums[i]=-1

        cumSum=0
        resCnt=0

        for i in range(n):
            cumSum+=nums[i]
            minTarget=0
            maxTarget=cumSum+offset-1
            targetIdx=cumSum+offset
            
            resCnt+= self.query(0,minTarget,maxTarget,0,2*n,seg)

            self.update(0,1,targetIdx,0,2*n,seg)
        
        return resCnt
