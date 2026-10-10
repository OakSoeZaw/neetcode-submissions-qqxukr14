class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS, COLUMNS = len(board), len(board[0])

        path = set()

        def dfs(r, c, index):
            if index == len(word):
                return True
            if (r >= ROWS or c >= COLUMNS or r < 0 or c < 0 
                or board[r][c] != word[index] or (r, c) in path):
                return
            
            path.add((r,c))
            res = (dfs(r + 1, c, index +1) or
                    dfs(r - 1, c, index + 1) or
                    dfs(r, c + 1, index + 1) or
                    dfs(r, c - 1, index + 1))
            path.remove((r,c))
            return res
        
        for i in range(ROWS):
            for j in range(COLUMNS):
                if dfs(i, j, 0): return True
        return False

        
            
            

        