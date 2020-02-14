class Solution {
public:
    void markAdj(vector<vector<char>> &board, int i, int j, int &rows, int &cols)
    {
        if(i > 0 && board[i-1][j] == 'O')
        {
            board[i-1][j] = 'y';
            markAdj(board, i-1, j, rows, cols);
        }
        if(i < rows - 1 && board[i+1][j] == 'O')
        {
            board[i+1][j] = 'y';
            markAdj(board, i+1, j, rows, cols);
        }
        if(j > 0 && board[i][j-1] == 'O')
        {
            board[i][j-1] = 'y';
            markAdj(board, i, j-1, rows, cols);
        }
        if(j < cols - 1 && board[i][j+1] == 'O')
        {
            board[i][j+1] = 'y';
            markAdj(board, i, j+1, rows, cols);
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(!rows)
        {
            return;
        }
        int cols = board[0].size();
        int i, j, k;
        char c;
        for(j = 0; j < cols; j++)
        {
            if(board[0][j] == 'O')
            {
                board[0][j] = 'y';
            }
            if(board[rows-1][j] == 'O')
            {
                board[rows-1][j] = 'y';
            }
        }
        for(i = 1; i < rows-1; i++)
        {
            if(board[i][0] == 'O')
            {
                board[i][0] = 'y';
            }
            if(board[i][cols - 1] == 'O')
            {
                board[i][cols - 1] = 'y';
            }
        }
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                if(board[i][j] == 'y')
                {
                    markAdj(board, i, j, rows, cols);
                }
            }
        }
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                c = board[i][j];
                if(c == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(c == 'y')
                {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};