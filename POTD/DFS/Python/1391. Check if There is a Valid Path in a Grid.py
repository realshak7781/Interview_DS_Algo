class Solution:
    
    possibleDir = {
        1: {'L', 'R'},
        2: {'U', 'D'},
        3: {'L', 'D'},
        4: {'R', 'D'},
        5: {'L', 'U'},
        6: {'R', 'U'}
    }

    coordMap = {
        'U': (-1, 0),
        'D': (1, 0),
        'L': (0, -1),
        'R': (0, 1)
    }

    def getOppositeDir(self,cur: str):
        opposites = {'L': 'R', 'R': 'L', 'D': 'U', 'U': 'D'}
        return opposites[cur]

    def hasValidPath(self, grid: list[list[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        vis = [[False] * n for _ in range(m)]
        return self.dfs(0, 0, vis, grid, m, n)

    def dfs(self, i: int, j: int, vis: list[list[bool]], grid: list[list[int]], m: int, n: int):
        if i == m - 1 and j == n - 1:
            return True
        
        vis[i][j] = True

        for direction in self.possibleDir[grid[i][j]]:
            oppositeDir = self.getOppositeDir(direction)
            
            dr, dc = self.coordMap[direction]
            nx, ny = i + dr, j + dc

            if 0 <= nx < m and 0 <= ny < n and not vis[nx][ny]:
                if oppositeDir in self.possibleDir[grid[nx][ny]]:
                    if self.dfs(nx, ny, vis, grid, m, n):
                        return True      
        vis[i][j] = False
        return False
