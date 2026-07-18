class Solution {
public:
    vector<int> dirs={0,1,0,-1,0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans=max(ans,dfs(i,j,vis,grid,0));
                }
            }
        }
        return ans;
    }

    int dfs(int x,int y,vector<vector<bool>>& vis,vector<vector<int>>& grid,int count){
        vis[x][y]=true;
        count++;
        for(int i=0;i<4;i++){
            int nx=x+dirs[i];
            int ny=y+dirs[i+1];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==1 && 
            !vis[nx][ny]){
                count = dfs(nx,ny,vis,grid,count);
            }
        }
        return count;
    }
};