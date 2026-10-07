class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = False

    def addWord(self, word):
        curr = self
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.word = True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()

        for w in words:
            root.addWord(w)

        ROWS, COLUMNS = len(board), len(board[0])
        res, visited = set(), set()

        def dfs(r, c, word, node):
            if (
                r < 0
                or c < 0
                or r == ROWS
                or c == COLUMNS
                or board[r][c] not in node.children
                or (r, c) in visited
            ):
                return
            
            visited.add((r, c))
            node = node.children[board[r][c]]
            word += board[r][c]
            if node.word:
                res.add(word)
            
            dfs(r +1, c, word, node)
            dfs(r -1, c, word, node)
            dfs(r, c +1, word, node)
            dfs(r, c - 1, word, node)

            visited.remove((r, c))

        for r in range(ROWS):
            for c in range(COLUMNS):
                dfs(r, c, "", root)
            
        return list(res)
