class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);
    }
    public boolean solve(char[][] board){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    for(char n='1';n<='9';n++){
                        if(isValid(board,r,c,n)){
                            board[r][c]=n;

                            if(solve(board))return true;

                            board[r][c]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isValid(char[][] board,int r,int c,char n){
        for(int i=0;i<9;i++){
            if(board[r][i]==n)return false;
            if(board[i][c]==n)return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==n)return false;
        }
        return true;
    }
}