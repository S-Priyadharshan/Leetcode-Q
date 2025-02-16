class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rows[9];
        unordered_set<char>cols[9];
        unordered_set<char>sq[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
            
            char num = board[i][j];
            int sqi = (i/3) * 3 + (j/3);
            if(rows[i].count(num)||cols[j].count(num)||sq[sqi].count(num)) return false;

            rows[i].insert(num);
            cols[j].insert(num);
            sq[sqi].insert(num);
            }
        }
        return true;
    }
};