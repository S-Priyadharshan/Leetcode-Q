class Solution {
public:
    vector<int>dirs = {0,1,0,-1,0};
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }

    void dfs(int x,int y,vector<vector<bool>>& vis,vector<vector<char>>& board){
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int nx=x+dirs[i];
            int ny=y+dirs[i+1];

            if(nx>=0 && ny>=0 && nx<board.size() && ny<board[0].size() && 
            !vis[nx][ny] && board[nx][ny]=='O'){
                dfs(nx,ny,vis,board);
            }
        }
    }
};