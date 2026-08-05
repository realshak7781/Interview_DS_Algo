

class Solution:
    def func(self,s,min_sum,max_sum,MOD):

        @cache
        def solve(pos,prevSum,isLeadingZero,isPartEqual):
            if pos>=len(s):
                if prevSum>=min_sum and prevSum<=max_sum:
                    return 1
                return 0
            
            upper_digit = int(s[pos]) if isPartEqual else 9
            digitLimit = min(max_sum - prevSum, upper_digit)

            totalCount=0
            for digit in range(digitLimit+1):
                newIsLeadingZero=isLeadingZero and (digit==0)
                if newIsLeadingZero:
                    totalCount=(totalCount+solve(
                        pos+1,
                        prevSum,
                        newIsLeadingZero,
                        False
                    ))%MOD
                else:
                    totalCount=(totalCount+solve(
                        pos+1,
                        prevSum+digit,
                        False,
                        isPartEqual and (digit==upper_digit)
                    ))%MOD
            
            return totalCount%MOD
        

        res=solve(0,0,True,True)%MOD

        return res

    def count(self, num1: str, num2: str, min_sum: int, max_sum: int) -> int:
        # FUNC BRINGS THE COUNT OF SUCH X NO WHICH STATISFIES THE CONDN
        MOD=10**9+7
        Y=self.func(num2,min_sum,max_sum,MOD)
        num1Val=int(num1)-1
        num1Str=str(num1Val)
        X=self.func(num1Str,min_sum,max_sum,MOD)

        res_count=(Y - X + MOD) % MOD

        return res_count
