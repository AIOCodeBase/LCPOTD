class Solution {
    public boolean isValidSudoku(char[][] board) {
        int N = 9;
        HashSet<Character>[] rowSet = new HashSet[N];
        HashSet<Character>[] colSet = new HashSet[N];
        HashSet<Character>[] squareSet = new HashSet[N];
        for (int r = 0; r < N; r++) {
            rowSet[r] = new HashSet<>();
            colSet[r] = new HashSet<>();
            squareSet[r] = new HashSet<>();
        }
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];
                if (val == '.') continue;
                int sPos = (r / 3) * 3 + c / 3;
                if (rowSet[r].contains(val) || colSet[c].contains(val) || squareSet[sPos].contains(val))
                    return false;
                rowSet[r].add(val);
                colSet[c].add(val);
                squareSet[sPos].add(val);
            }
        }
        return true;
    }
}