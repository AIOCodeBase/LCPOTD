class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def getBit(x, k):
            return (x >> k) & 1
        
        N = 9
        rows, cols, squares = [0] * N, [0] * N, [0] * N
        for r in range(N):
            for c in range(N):
                if board[r][c] == ".": continue
                val = int(board[r][c])
                sr, sc = r // 3, c // 3
                sPos = sr * 3 + sc
                if getBit(rows[r], val) or getBit(cols[c], val) or getBit(squares[sPos], val):
                    return False
                rows[r] |= 1 << val
                cols[c] |= 1 << val
                squares[sPos] |= 1 << val
        return True