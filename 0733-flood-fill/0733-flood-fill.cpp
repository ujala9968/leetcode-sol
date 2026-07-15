class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col,
             int oldColor, int color) {

        if (row < 0 || col < 0 ||
            row >= image.size() || col >= image[0].size())
            return;

        if (image[row][col] != oldColor)
            return;

        // Change color
        image[row][col] = color;

        // Visit 4 directions
        dfs(image, row - 1, col, oldColor, color); // Up
        dfs(image, row + 1, col, oldColor, color); // Down
        dfs(image, row, col - 1, oldColor, color); // Left
        dfs(image, row, col + 1, oldColor, color); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        // Avoid infinite recursion
        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};