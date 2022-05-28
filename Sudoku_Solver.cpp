class Solution {
public:
    bool good(vector<vector<char>> board,int n,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
            {
                return false;
            }
            if(board[i][col]==c)
            {
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            {
                return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(good(board,n,i,j,k))
                        {
                            board[i][j]=k;
                            if(helper(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j]='.';
                            }
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        helper(board);
    }
};
