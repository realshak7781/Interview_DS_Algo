class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        m=len(word1)
        n=len(word2)
        rightSideMatchLen=[0]*(m+1)
        rightSideMatchLen[m]=0

        i,j=m-1,n-1
        matchCount=0
        while i>=0 and j>=0:
            if word1[i]==word2[j]:
                matchCount+=1
                rightSideMatchLen[i]=matchCount
                i-=1
                j-=1
            else:
                rightSideMatchLen[i]=matchCount
                i-=1
        

        while i>=0:
            rightSideMatchLen[i]=matchCount
            i-=1
        

        matchPowers=1


        i,j=0,0
        res=[]
        while i<m and j<n:
            if word1[i]==word2[j]:
                res.append(i)
                i+=1
                j+=1
            else:
                if matchPowers>0 and rightSideMatchLen[i+1]>=(n-j-1):
                    matchPowers-=1
                    res.append(i)
                    i+=1
                    j+=1
                else:
                    i+=1
        

        if len(res)==len(word2):
            return res
        

        return []
