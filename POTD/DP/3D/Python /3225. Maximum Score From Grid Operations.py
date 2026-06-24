

class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        colPrefSum = [[0] * (n + 1) for _ in range(n + 1)]

        for col in range(1, n + 1):
            for row in range(1, n + 1):
                colPrefSum[row][col] = colPrefSum[row - 1][col] + grid[row - 1][col - 1]
        
        @cache
        def solve(prev_h: int, col: int, prev_taken: bool) -> int:
            if col >= n:
                return 0

            result = 0

            for height in range(-1, n):
                cur_h = height
                prevScore = 0
                curScore = 0

                if prev_h > cur_h:
                    curScore = colPrefSum[prev_h + 1][col + 1] - colPrefSum[cur_h + 1][col + 1]
                
                if not prev_taken and cur_h > prev_h:
                    prevScore = colPrefSum[cur_h + 1][col] - colPrefSum[prev_h + 1][col]
                
                curTaken = curScore + prevScore + solve(cur_h, col + 1, True)
                curNotTaken = prevScore + solve(cur_h, col + 1, False)

                result = max(result, curTaken, curNotTaken)
            
            return result

        return solve(-1, 0, False)
