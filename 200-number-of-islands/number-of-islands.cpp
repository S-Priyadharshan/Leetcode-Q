class Solution {
public:
    vector<int> dirs={0,1,0,-1,0};
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }

    void dfs(int x,int y,vector<vector<bool>>& vis,vector<vector<char>>& grid){
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int nx=x+dirs[i];
            int ny=y+dirs[i+1];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[x][y]=='1' && 
            !vis[nx][ny]){
                dfs(nx,ny,vis,grid);
            }
        }
    }
};