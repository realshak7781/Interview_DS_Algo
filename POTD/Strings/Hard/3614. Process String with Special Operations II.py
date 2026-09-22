class Solution:
    def processStr(self, s: str, k: int) -> str:
        n=len(s)

        l=0
        for i in range(n):
            ch=s[i]

            if ch.islower():
                l+=1
            elif ch=='#':
                l*=2
            elif ch=='*':
                if l>0:
                    l-=1
        
        if l<=k:
            return '.'

        
        # traverse in a reverse direction to reverse the effect of special ops

        for i in range(n-1,-1,-1):
            ch=s[i]

            if ch.islower():
                l-=1
            elif ch=='#':
                l=l/2
                if(k>=l):
                    k-=l
            elif ch=='*':
                l+=1
            elif ch=='%':
                k=l-k-1
            
            

            if l==k:
                return s[i]
        

        return '.'
