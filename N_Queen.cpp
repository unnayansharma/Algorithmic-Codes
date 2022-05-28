class Solution {
public:
    bool issafe(int row,int col,vector<string> board,int n)
    {
        int duprow=row;
        int dupcol=col;
        while(duprow>=0 && dupcol>=0)
        {
            if(board[duprow][dupcol]=='Q')
            {
                return false;
            }
            duprow--;
            dupcol--;
        }
        duprow=row;
        dupcol=col;
        while(dupcol>=0)
        {
            if(board[duprow][dupcol]=='Q')
            {
                return false;
            }
            dupcol--;
        }
        duprow=row;
        dupcol=col;
        while(duprow<n && dupcol>=0)
        {
            if(board[duprow][dupcol]=='Q')
            {
                return false;
            }
            duprow++;
            dupcol--;
        }
        return true;
    }
    void solve(int col,int n,vector<string>& board,vector<vector<string>>& ans)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(issafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,n,board,ans);
        return ans;
    }
};
