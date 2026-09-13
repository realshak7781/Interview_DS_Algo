# APPROACH 2 : USING SEGMENT TREE FOR RANGE MAX AND MIN AND MAX HEAP FOR TOP K PATTERN
# TIME : O(N) + o(N*LOGN + K*LOGN)
# SPACE : O(N) + O(LOGN) RECURSIVE STACK SPACE

class Solution:

    def buildTree(self,segMax,segMin,nums,nodeIdx,l,r):
        if l==r:
            segMax[nodeIdx]=nums[l]
            segMin[nodeIdx]=nums[l]
            return
        
        mid=l+(r-l)//2

        self.buildTree(segMax,segMin,nums,2*nodeIdx+1,l,mid)
        self.buildTree(segMax,segMin,nums,2*nodeIdx+2,mid+1,r)

        segMax[nodeIdx]=max(segMax[2*nodeIdx+1],segMax[2*nodeIdx+2])
        segMin[nodeIdx]=min(segMin[2*nodeIdx+1],segMin[2*nodeIdx+2])
    
    def rangeMax(self,segMax,nodeIdx,l,r,ql,qr,nums):
        # u can write the lazy code here but we will skip it for now since
        # we are not making any updates

        if ql>r or l>qr:
            return float('-inf')
        
        if l>=ql and r<=qr:
            return segMax[nodeIdx]
        
        mid=l+(r-l)//2
        leftMax=self.rangeMax(segMax,2*nodeIdx+1,l,mid,ql,qr,nums)
        rightMax=self.rangeMax(segMax,2*nodeIdx+2,mid+1,r,ql,qr,nums)

        return max(leftMax,rightMax)

    def rangeMin(self,segMin,nodeIdx,l,r,ql,qr,nums):

        if ql>r or l>qr:
            return float('inf')
        
        if l>=ql and r<=qr:
            return segMin[nodeIdx]
        
        mid=l+(r-l)//2
        leftMin=self.rangeMin(segMin,2*nodeIdx+1,l,mid,ql,qr,nums)
        rightMin=self.rangeMin(segMin,2*nodeIdx+2,mid+1,r,ql,qr,nums)

        return min(leftMin,rightMin)
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        n=len(nums)
        segMax = [0] * (4 * n)
        segMin = [0] * (4 * n)
        self.buildTree(segMax,segMin,nums,0,0,n-1)

        maxHeap=[]

        for i in range(n):
            ql,qr=i,n-1
            maxi=self.rangeMax(segMax,0,0,n-1,ql,qr,nums)
            mini=self.rangeMin(segMin,0,0,n-1,ql,qr,nums)
            diffVal=maxi-mini

            heapq.heappush(maxHeap,(-diffVal,ql,qr))

        resValSum=0
        while k>0:
            negDiffVal,ql,qr=heapq.heappop(maxHeap)
            actualDiffVal=-negDiffVal
            resValSum+=actualDiffVal

            newQr=qr-1

            if newQr>=ql:
                maxi=self.rangeMax(segMax,0,0,n-1,ql,newQr,nums)
                mini=self.rangeMin(segMin,0,0,n-1,ql,newQr,nums)
                diffVal=maxi-mini
                heapq.heappush(maxHeap, (-diffVal, ql, newQr))
            
            k-=1
        
        return resValSum




# Approach 1 : using minHeap + brute force
# TIME : O(N*N*LOGK)
# SPACE : O(K)

class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        # by default python has  a minHeap
        # to have a maxheap,push negatives
        n=len(nums)
        minHeap=[]

        for i in range(n):
            maxi=nums[i]
            mini=nums[i]
            for j in range(i,n):
                maxi=max(maxi,nums[j])
                mini=min(mini,nums[j])
                diff=maxi-mini

                if len(minHeap)<k:
                    heapq.heappush(minHeap,diff)
                else:
                    if minHeap[0]<diff:
                        minElem=heapq.heappop(minHeap)
                        heapq.heappush(minHeap,diff)
        

        res=0
        while minHeap:
            res+=heapq.heappop(minHeap)
        
        return res
