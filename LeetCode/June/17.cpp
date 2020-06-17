class Solution {
public:
    int r, c;
    void ff(vector<vector<char>>& board, int i, int j, char p, char n) {
        if (i < 0 || i >= r || j < 0 || j >= c)
            return;
        if (board[i][j] != p)
            return;
        board[i][j] = n;
        ff(board, i, j + 1, p, n);
        ff(board, i + 1, j, p, n);
        ff(board, i, j - 1, p, n);
        ff(board, i - 1, j, p, n);
    }
    void solve(vector<vector<char>>& board) {
        int j, i, x = 0;
        r = board.size();
        if (r == 0)
            return;
        c = board[0].size();
        for (i = 0; i < r; ++i)
            for (j = 0; j < c; ++j)
                if (board[i][j] == 'O')
                    board[i][j] = '-';
        for (i = 0; i < c; ++i)
            if (board[0][i] == '-')
                ff(board, 0, i, '-', 'O');
        for (i = 0; i < c; ++i)
            if (board[r-1][i] == '-')
                ff(board, r-1, i, '-', 'O');
        for (i = 0; i < r; ++i)
            if (board[i][0] == '-')
                ff(board, i, 0, '-', 'O');
        for (i = 0; i < r; ++i)
            if (board[i][c-1] == '-')
                ff(board, i, c-1, '-', 'O');
        
        for (i = 1; i < r - 1; ++i)
            for (j = 1; j < c - 1; ++j)
                if (board[i][j] == '-')
                    board[i][j] = 'X';
    }
};
