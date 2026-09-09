class Solution {
public:
    bool check(int n,vector<string>&board,int j,int i)
    {
        int col=j;
        int row=i;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
            {
                return 0;
            }
            row--;
            col--;
        }
        row=i;
        col=j;
        while(row>=0 && col<n)
        {
            if(board[row][col]=='Q')
            {
                return 0;
            }
            row--;
            col++;
        }
        return 1;
    }
    void find(int row,int n,vector<vector<string>>&ans,vector<string>&board,vector<bool>&column)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(column[j]==0 && check(n,board,j,row))
            {
                board[row][j]='Q';
                column[j]=1;
                find(row+1,n,ans,board,column);
                column[j]=0;
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<bool>column(n,0);
        find(0,n,ans,board,column);
        return ans;
    }
};