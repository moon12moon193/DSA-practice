class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m) {

            return false;
        }
        return true;
    }
    bool bfs(vector<vector<int>> grid, int x[4], int y[4], int n, int m,
             int guess) {
        vector<vector<bool>> vis(n);
        for (int i = 0; i < n; i++) {
            vector<bool> t(m, false);
            vis[i] = t;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            if (row == n - 1 && col == m - 1) {
                return true;
            }
            for (int k = 0; k < 4; k++) {
                int r = row + x[k];
                int c = col + y[k];

                if (isValid(r, c, n, m) && vis[r][c] == false &&
                    guess >= grid[r][c]) {
                    q.push({r, c});
                    vis[r][c] = true;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int low = grid[0][0];
        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                high = max(high, grid[i][j]);
            }
        }

        int ans = 0;
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        while (low <= high) {
            int guess = low + (high - low) / 2;
            if (bfs(grid, x, y, n, m, guess)) {
                ans = guess;
                high = guess - 1;
            } else {
                low = guess + 1;
            }
        }
        return ans;
    }
};
