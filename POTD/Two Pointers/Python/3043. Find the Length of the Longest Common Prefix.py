# TIME : O(MAX(M,N))
# SPACE : O(M+N)

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        s1=set()
        s2=set()

        for val in arr1:
            s=str(val)

            for i in range(len(s)):
                prefix=s[:i+1]
                s1.add(prefix)

        for val in arr2:
            s=str(val)

            for i in range(len(s)):
                prefix=s[:i+1]
                s2.add(prefix)
        
        maxLen=0

        for s in s1:
            if s in s2:
                maxLen=max(maxLen,len(s))
        
        for s in s2:
            if s in s1:
                maxLen=max(maxLen,len(s))
        
        return maxLen

