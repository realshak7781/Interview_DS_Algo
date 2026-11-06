
# approach 1 : time : O(n)
# space  : o(n)
class Solution:
    def stoneGameIII(self, stoneValue: list[int]) -> str:
        n=len(stoneValue)
        total_score=sum(stoneValue)

        @cache
        def solve(idx,isAliceTurn):
            # solve define as starting at idx with alice , what max score she can get
            if idx>=n:
                return 0
            
            my_score=float('-inf')
            opp_score=float('inf')
            agg=0
            for offset in range(0,3):
                new_idx=idx+offset

                if new_idx<n:
                    agg+=stoneValue[new_idx]
                    if isAliceTurn:
                        my_score=max(my_score,agg+solve(new_idx+1,isAliceTurn^1))
                    else:
                        opp_score=min(opp_score,solve(new_idx+1,isAliceTurn^1))
            

            return (my_score if isAliceTurn else opp_score)
        

        alice_score=solve(0,1)
        bob_score=total_score-alice_score

        if alice_score>=bob_score:
            return "Alice" if alice_score>bob_score else "Tie"
        return "Bob"

            
