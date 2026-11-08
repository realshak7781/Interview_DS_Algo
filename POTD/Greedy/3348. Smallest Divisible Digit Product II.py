class Solution:
    def gcd(self,a,b):
        if b==0:
            return a
        
        return self.gcd(b,a%b)
    
    def formRemStr(self,remLen:int,num:int)->str:
        resStr=""

        for dig in range(9,1,-1):

            while num%dig==0:
                resStr+=str(dig)
                num//=dig
        
        while len(resStr)<remLen:
            resStr+=str(1)
        

        reversed_res =resStr[::-1]

        return reversed_res
    def smallestNumber(self, num: str, t: int) -> str:
        n=len(num)
        primeFactors = {2, 3, 5, 7}

        temp=t
        for f in primeFactors:
            while temp%f==0:
                temp//=f
        

        if temp!=1:
            return "-1"
        
        # precompute
        remFac=[0]*(n+1)
        remFac[0]=t
        zeroIdx=n
        for i in range(0,n):
            dig=ord(num[i])-ord('0')
            if dig==0:
                zeroIdx=i
                break
            remFac[i+1]=remFac[i]//self.gcd(remFac[i],dig)
        
        if remFac[n]==1:
            return num

        if zeroIdx==n:
            zeroIdx=n-1
            # out of bound check
        for i in range(zeroIdx,-1,-1):
            required=remFac[i]
            remLen=n-i-1

            startDig=ord(num[i])-ord('0')+1

            for dig in range(startDig,10):
                further_required=required//self.gcd(remFac[i],dig)

                remStr=self.formRemStr(remLen,further_required)

                if len(remStr)==remLen:
                    res=num[0:i]
                    res+=str(dig)
                    res+=remStr
                    return res
        

        return self.formRemStr(n+1,t)
