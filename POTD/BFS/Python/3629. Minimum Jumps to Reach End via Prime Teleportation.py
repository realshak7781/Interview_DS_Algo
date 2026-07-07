class Solution:
    def sieve(self,nums:List[int],maxi:int):
        isPrime=[True]*(maxi+1)
        isPrime[0]=False
        isPrime[1]=False

        p=2
        while p*p<=maxi:
            if isPrime[p]:
                for mul in range(p*p,maxi+1,p):
                    isPrime[mul]=False
            
            p+=1
        
        return isPrime
    
    def getPrimeFactors(self,x:int,isPrime:List[bool]):
        primes=[]

        p=2
        while p*p<=x:
            if x%p==0 and isPrime[p]:
                primes.append(p)

                while x%p==0:
                    x//=p
            
            p+=1
        
        if x>1:
            primes.append(x)
        
        return primes

    def minJumps(self, nums: List[int]) -> int:
        n=len(nums)
        maxi=max(nums)

        isPrime=self.sieve(nums,maxi)
        mp=defaultdict(list)


        for i,x in enumerate(nums):
            primes=self.getPrimeFactors(x,isPrime)

            for p in primes:
                mp[p].append(i)
        
        dq : deque[tuple[int,int]]=deque()

        dq.append((0,0))
        vis=[False]*n
        vis[0]=True


        while dq:
            idx,steps=dq.popleft()

            if idx==n-1:
                return steps
            
            if idx-1>=0 and not vis[idx-1]:
                dq.append((idx-1,steps+1))
                vis[idx-1]=True

            if idx+1<n and not vis[idx+1]:
                dq.append((idx+1,steps+1))
                vis[idx+1]=True
            
            if not isPrime[nums[idx]]:
                continue
            
            if nums[idx] in mp:
                for pos in mp[nums[idx]]:
                    if not vis[pos]:
                        vis[pos]=True
                        dq.append((pos,steps+1))
                
                del mp[nums[idx]]
        
        return -1
