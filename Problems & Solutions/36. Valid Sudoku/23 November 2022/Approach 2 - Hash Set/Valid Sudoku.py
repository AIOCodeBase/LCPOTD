class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        N = 9
        rowSet = [set() for _ in range(N)]
        colSet = [set() for _ in range(N)]
        squareSet = [set() for _ in range(N)]

        for r in range(N):
            for c in range(N):
                if board[r][c] == ".": continue
                sr, sc = r // 3, c // 3
                sPos = sr * 3 + sc
                if board[r][c] in rowSet[r] or board[r][c] in colSet[c] or board[r][c] in squareSet[sPos]:
                    return False
                rowSet[r].add(board[r][c])
                colSet[c].add(board[r][c])
                squareSet[sPos].add(board[r][c])

        return True