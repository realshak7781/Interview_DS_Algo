# brute force using game theory and net difference in score based on who starts firsr
class Solution:
    def predictTheWinner(self, nums: list[int]) -> bool:
        n=len(nums)
        def solve(i,j):
            if i==j:
                return nums[i]
            

            take_i=nums[i]-solve(i+1,j)
            take_j=nums[j]-solve(i,j-1)

            return max(take_i,take_j)

        return solve(0,n-1)>=0



# brute force using p1Turn variable
class Solution:
    def predictTheWinner(self, nums: list[int]) -> bool:
        n=len(nums)
        total_score=sum(nums)

        def solve(i,j,p1Turn):
            if i>j:
                return 0
        
            if p1Turn:
                take_i=nums[i]+solve(i+1,j,p1Turn^1)
                take_j=nums[j]+solve(i,j-1,p1Turn^1)
                return max(take_i,take_j)
            else:
                take_i=0+solve(i+1,j,p1Turn^1)
                take_j=0+solve(i,j-1,p1Turn^1)
                return min(take_i,take_j)
            
            return 0
        
        p1Score=solve(0,n-1,1)
        p2Score=total_score-p1Score

        return p1Score>=p2Score
