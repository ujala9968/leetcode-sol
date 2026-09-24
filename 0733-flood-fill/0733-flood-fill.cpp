class Solution {
public:
    void solve(vector<vector<int>>& image,
               int cr, int cc,
               int color, int oldcolor) {

        // Out of bounds
        if (cr < 0 || cc < 0 ||
            cr >= image.size() ||
            cc >= image[0].size()) {
            return;
        }

        // Only change cells having old color
        if (image[cr][cc] != oldcolor) {
            return;
        }

        // Fill current cell
        image[cr][cc] = color;

        // Up
        solve(image, cr - 1, cc, color, oldcolor);

        // Down
        solve(image, cr + 1, cc, color, oldcolor);

        // Left
        solve(image, cr, cc - 1, color, oldcolor);

        // Right
        solve(image, cr, cc + 1, color, oldcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        int oldcolor = image[sr][sc];

        // Nothing to change
        if (oldcolor == color) {
            return image;
        }

        solve(image, sr, sc, color, oldcolor);

        return image;
    }
};