class Solution {
public:
    // Directions: Up, Down, Left, Right
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    // Check if the cell is inside the grid
    bool valid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    // DFS to mark all connected land cells
    void dfs(vector<vector<char>>& grid, int n, int m,
             int i, int j, vector<vector<bool>>& visited) {

        visited[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];

            if (valid(row, col, n, m) &&
                grid[row][col] == '1' &&
                !visited[row][col]) {

                dfs(grid, n, m, row, col, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int count = 0;

        // Traverse every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // New island found
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(grid, n, m, i, j, visited);
                }
            }
        }

        return count;
    }
};