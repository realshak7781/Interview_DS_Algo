class Solution:
    def count_of_unique_digits(self,num:int)->int:

        if num<10:
            return num
        
        s=str(num)

        @cache
        def solve(pos,mask,isLeadingZero,isPartEqual):
            if pos>=len(s):
                return 0 if isLeadingZero else 1
            
            digit_lim= int(s[pos]) if isPartEqual else 9
            total_count=0

            for digit in range(digit_lim+1):
                if isLeadingZero and digit==0:
                    total_count+=solve(
                        pos+1,
                        mask,
                        True,
                        False
                    )
                elif ((mask >> digit) & 1) == 0:
                    new_mask=mask | (1<<digit)
                    NewisPartEqual=isPartEqual and (digit==digit_lim)

                    total_count+=solve(
                        pos+1,
                        new_mask,
                        False,
                        NewisPartEqual
                    )
            
            return total_count
        
        return solve(0,0,True,True)

    def numDupDigitsAtMostN(self, n: int) -> int:
        res_count=n - self.count_of_unique_digits(n)

        return res_count
