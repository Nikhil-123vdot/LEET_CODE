class Solution {
public:
    bool check(int num,vector<vector<char>>&board,int i,int j)
    {
        char a= '0'+num;
        for(int col=0;col<9;col++)
        {
            if(board[i][col]==a)
            {
                return 0;
            }
        }
        for(int row=0;row<9;row++)
        {
            if(board[row][j]==a)
            {
                return 0;
            }
        }
        int row=(i/3)*3;
        int col=(j/3)*3;
        for(int r=row;r<row+3;r++)
        {
            for(int c=col;c<col+3;c++)
            {
                if(board[r][c]==a)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool find(vector<vector<char>>& board,int i,int j)
    {
        if(i==9)
        {
            return 1;
        }
        if(j==9)
        {
            return find(board,i+1,0);
        }
        if(board[i][j]!='.')
        {
            return find(board,i,j+1);
        }
        for(int num=1;num<=9;num++)
        {
            if(check(num,board,i,j))
            {
                board[i][j]='0'+num;
                if(find(board,i,j))
                {
                    return 1;
                }
                board[i][j]='.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        find(board,0,0);
    }
};