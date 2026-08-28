class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m) {
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& board, int r, int c, int x[4], int y[4],
             int n, int m) {
        board[r][c] = '#';
        for (int k = 0; k < 4; k++) {
            int row = r + x[k];
            int col = c + y[k];
            if (isValid(row, col, n, m) && board[row][col] == 'O') {
                dfs(board, row, col, x, y, n, m);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        int n = board.size();
        int m = board[0].size();
        // For First Row
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i, x, y, n, m);
            }
        }
        // For Last Row
        for (int i = 0; i < m; i++) {
            if (board[n - 1][i] == 'O') {
                dfs(board, n - 1, i, x, y, n, m);
            }
        }
        // For First Column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, x, y, n, m);
            }
        }
        // For Last Column
        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] == 'O') {
                dfs(board, i, m - 1, x, y, n, m);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
