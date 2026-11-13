
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                for (int k = 0; k < 8; k++) {
                    int r = i + dx[k];
                    int c = j + dy[k];

                    if (r >= 0 && r < m &&
                        c >= 0 && c < n &&
                        (board[r][c] == 1 ||
                         board[r][c] == 2)) {
                        live++;
                    }
                }

                if (board[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = 2;
                }
                else {
                    if (live == 3)
                        board[i][j] = 3;
                }
            }
        }

        // Convert temporary values to final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;

                else if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};
