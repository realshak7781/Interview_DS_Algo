# time : O(n)
# space : o(1)

class Solution:
    def check(self,alphabet):
        res=(alphabet[0]>=1) and (alphabet[1]>=1) and (alphabet[2]>=1)
        return res

    def numberOfSubstrings(self, s: str) -> int:
        n=len(s)
        i,j=0,0
        alphabet=[0]*3

        # hanlding the first char
        alphabet[ord(s[0])-ord('a')]+=1

        resSubs=0
        while i<n and j<n:
            if self.check(alphabet):
                totalSubsformed=n-j
                resSubs+=totalSubsformed
                charIdx=ord(s[i])-ord('a')
                alphabet[charIdx]-=1
                i+=1
            else:
                j+=1
                if j<n:
                    charIdx=ord(s[j])-ord('a')
                    alphabet[charIdx]+=1
        
        return resSubs
            
