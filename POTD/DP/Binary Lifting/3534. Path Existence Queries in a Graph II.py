# TIME : O(Q*LOG(N))
# SPACE : O(LOG(N)*N)

class Solution:
    def findIdx(self,low,high,arr,target):
        res=-1
        while low<=high:
            mid=low+(high-low)//2

            if arr[mid][0]<=target:
                res=mid
                low=mid+1
            else:
                high=mid-1
        
        return res
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        arr=[]

        for i in range(n):
            arr.append((nums[i],i))
        
        arr.sort(key=lambda x : x[0])
        cols=math.floor(math.log2(n))+1
        up=[[-1]*cols for _ in range(n)]

        # fill the up array for up[node][0]
        for i in range(n):
            maxValReach=arr[i][0]+maxDiff
            # try to find idx of val in arr<=maxValReach using BianrySearch
            # that is the node reachable from current nodei in 2^0 jumps alka 1 jump
            idx=self.findIdx(i,n-1,arr,maxValReach)
            if idx==-1:
                up[i][0]=i
            else:
                up[i][0]=idx
        

        # use dp to fill rest of Up array
        for j in range(1,cols):
            for node in range(0,n):
                if up[node][j-1]!=-1:
                    up[node][j]=up[up[node][j-1]][j-1]
        

        nodeIdxMp=defaultdict(int)
        for i in range(n):
            node=arr[i][1]
            nodeIdxMp[node]=i

        res=[]
        for q in queries:
            a=nodeIdxMp[q[0]]
            b=nodeIdxMp[q[1]]

            if a==b:
                res.append(0)
                continue
            if a>b:
                a,b=b,a
            
            curr=a
            jumps=0
            for j in range(cols-1,-1,-1):
                if up[curr][j]<b:
                    curr=up[curr][j]
                    jumps+=(1<<j)
            
            if up[curr][0]>=b:
                res.append(jumps+1)
            else:
                res.append(-1)
        
        return res
