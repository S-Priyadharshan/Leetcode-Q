class Solution {
public:
    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& cols, vector<bool>& mainDiag, vector<bool>& antiDiag,
                   vector<vector<string>>& results) {
        if(row==n){
            results.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            int d1=row-col+(n-1);
            int d2=row+col;

            if(cols[col] || mainDiag[d1] || antiDiag[d2]){
                continue;
            }

            board[row][col]='Q';
            cols[col]=mainDiag[d1]=antiDiag[d2]=true;

            backtrack(row+1,n,board,cols,mainDiag,antiDiag,results);

            board[row][col]='.';
            cols[col] = mainDiag[d1] = antiDiag[d2] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {    
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> cols(n, false);
        vector<bool> mainDiag(2 * n - 1, false);
        vector<bool> antiDiag(2 * n - 1, false);

        backtrack(0, n, board, cols, mainDiag, antiDiag, results);
        return results;
    }
};